#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glib.h>
#include <glib-object.h>
#include <ruby.h>

#ifdef HAVE_RUBY_ENCODING_H
  #include <ruby/encoding.h>
#endif

#include "libots.h"
#include "summarize.h"


void Init_summarize() {
 VALUE rb_mOts = rb_define_module("Summarize");
 rb_define_module_function(rb_mOts, "summarize", summarize, 4);
}

static VALUE summarize(const VALUE self, volatile VALUE rb_str, volatile VALUE rb_dict_file, const VALUE rb_ratio, const VALUE rb_topics) {
  #ifdef HAVE_RUBY_ENCODING_H
    int enc = rb_enc_find_index("UTF-8");
  #endif
  long int length = RSTRING_LEN(rb_str);
  char *text = StringValuePtr(rb_str);
  char *dictionary_file = StringValuePtr(rb_dict_file);
  int ratio = NUM2INT(rb_ratio);

  size_t result_len;
  OtsArticle *doc = ots_new_article();

  VALUE summary;
  VALUE topics;
  VALUE result;

  if (!ots_load_xml_dictionary(doc, dictionary_file)) {
    ots_free_article(doc);
    rb_raise(rb_eRuntimeError, "Cannot load dictionary file");
    return Qnil;
  }

  ots_parse_stream(text, length, doc);
  ots_grade_doc(doc);
  ots_highlight_doc(doc, ratio);

  summary = rb_str_new2(ots_get_doc_text(doc, &result_len));
  topics = rb_str_new2((const char *)doc->title);

  #ifdef HAVE_RUBY_ENCODING_H
    rb_enc_associate_index(summary, enc);
    rb_enc_associate_index(summary, enc);
  #endif

  ots_free_article(doc);

  if (rb_topics == Qtrue) {
    result = rb_ary_new();
    rb_ary_push(result, summary);
    rb_ary_push(result, topics);
    return result;
  } else {
    return summary;
  }
}
