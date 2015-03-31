#ifndef _BB_CODEC_H_
#define _BB_CODEC_H_

#include <protocol/memcache/bb_request.h>
#include <protocol/memcache/bb_response.h>

#include <buffer/cc_fbuf.h>
#include <cc_define.h>
#include <cc_metric.h>

/*          name                type            description */
#define CODEC_METRIC(ACTION)                                            \
    ACTION( request_perror,     METRIC_COUNTER, "# parsing error"      )\
    ACTION( request_swallow,    METRIC_COUNTER, "# lines swallowed"    )\
    ACTION( request_parse,      METRIC_COUNTER, "# requests parsed"    )\
    ACTION( request_get,        METRIC_COUNTER, "# get requests"       )\
    ACTION( request_gets,       METRIC_COUNTER, "# gets requests"      )\
    ACTION( request_delete,     METRIC_COUNTER, "# delete requests"    )\
    ACTION( request_set,        METRIC_COUNTER, "# set requests"       )\
    ACTION( request_add,        METRIC_COUNTER, "# add requests"       )\
    ACTION( request_replace,    METRIC_COUNTER, "# replace requests"   )\
    ACTION( request_cas,        METRIC_COUNTER, "# cas requests"       )\
    ACTION( request_append,     METRIC_COUNTER, "# append requests"    )\
    ACTION( request_prepend,    METRIC_COUNTER, "# prepend requests"   )\
    ACTION( request_incr,       METRIC_COUNTER, "# incr requests"      )\
    ACTION( request_decr,       METRIC_COUNTER, "# decr requests"      )\
    ACTION( request_stats,      METRIC_COUNTER, "# stats requests"     )\
    ACTION( request_quit,       METRIC_COUNTER, "# quit requests"      )\
    ACTION( response_cerror,    METRIC_COUNTER, "# composing error"    )\
    ACTION( response_compose,   METRIC_COUNTER, "# responses composed" )\
    ACTION( response_keyval,    METRIC_COUNTER, "# keyval responses"   )\
    ACTION( response_msg,       METRIC_COUNTER, "# static responses"   )\
    ACTION( response_int,       METRIC_COUNTER, "# int responses"      )\
    ACTION( response_stats,     METRIC_COUNTER, "# statsresponses"     )

rstatus_t parse_swallow(struct fbuf *buf);
rstatus_t parse_req_hdr(struct request *req, struct fbuf *buf);
rstatus_t parse_req_val(struct request *req, struct fbuf *buf);
rstatus_t parse_req(struct request *req, struct fbuf *buf);

rstatus_t compose_rsp_msg(struct fbuf *buf, rsp_index_t idx, bool noreply);
rstatus_t compose_rsp_uint64(struct fbuf *buf, uint64_t val, bool noreply);
rstatus_t compose_rsp_keyval(struct fbuf *buf, struct bstring *key, struct bstring *val, uint32_t flag, uint64_t cas);
rstatus_t compose_rsp_stats(struct fbuf *buf, struct metric marr[], unsigned int nmetric);
#endif /* _BB_CODEC_H_ */