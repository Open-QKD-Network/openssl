/* Extras for OQS extension */

#define ENCODE_UINT16(pbuf, i)  (pbuf)[index]   = (unsigned char)((i>>8) & 0xff); \
                                (pbuf)[index+1] = (unsigned char)((i   ) & 0xff)
#define DECODE_UINT16(i, pbuf)  i  = ((uint16_t) (pbuf)[index])   << 8; \
                                i |= ((uint16_t) (pbuf)[index+1])

/* Encodes two messages (classical and PQC) into one hybrid message:
   msg1_len || msg1 || msg2_len || msg2
   hybrid_msg is allocated in this function.
   Follows format specified in https://tools.ietf.org/html/draft-stebila-tls-hybrid-design-03
 */
static int OQS_encode_hybrid_message(const unsigned char* msg1, uint16_t  msg1_len,
                                     const unsigned char* msg2, uint16_t  msg2_len,
                                     unsigned char** hybrid_msg, uint16_t* hybrid_msg_len) {
  int index = 0;
  *hybrid_msg_len = msg1_len + msg2_len + (2 * sizeof(uint16_t));
  *hybrid_msg = OPENSSL_malloc(*hybrid_msg_len);
  if (*hybrid_msg == NULL) {
    return 0;
  }

  ENCODE_UINT16(*hybrid_msg, msg1_len);  
  index += sizeof(uint16_t);
  memcpy(*hybrid_msg + index, msg1, msg1_len);
  index += msg1_len;

  ENCODE_UINT16(*hybrid_msg, msg2_len);  
  index += sizeof(uint16_t);
  memcpy(*hybrid_msg + index, msg2, msg2_len);
  
  return 1;
}

/* Decodes hybrid message returning the classical and PQC messages:
   msg1_len || msg1 || msg2_len || msg2
   msg1 and msg2 are allocated in this function.
   Follows format specified in https://tools.ietf.org/html/draft-stebila-tls-hybrid-design-03
 */
static int OQS_decode_hybrid_message(const unsigned char* hybrid_msg,
                                     unsigned char** msg1, uint16_t* msg1_len,
                                     unsigned char** msg2, uint16_t* msg2_len) {
  int index = 0;
  DECODE_UINT16(*msg1_len, hybrid_msg);
  index += sizeof(uint16_t);
  *msg1 = OPENSSL_malloc(*msg1_len);
  if (*msg1 == NULL) {
    return 0;
  }
  memcpy(*msg1, hybrid_msg + index, *msg1_len);
  index += *msg1_len;

  DECODE_UINT16(*msg2_len, hybrid_msg);
  index += sizeof(uint16_t);
  *msg2 = OPENSSL_malloc(*msg2_len);
  if (*msg2 == NULL) {
    return 0;
  }
  memcpy(*msg2, hybrid_msg + index, *msg2_len);

  return 1;
}

/* Encodes three messages (classical, PQC and OpenQKD) into one triple message:
   msg1_len || msg1 || msg2_len || msg2 || msg3_len || msg3
   triple_msg is allocated in this function.
   Follows format specified in https://tools.ietf.org/html/draft-stebila-tls-hybrid-design-03
 */
static int OQKD_OQS_encode_triple_message(const unsigned char* msg1, uint16_t  msg1_len,
                                     const unsigned char* msg2, uint16_t  msg2_len,
                                     const unsigned char* msg3, uint16_t msg3_len,
                                     unsigned char** triple_msg, uint16_t* triple_msg_len) {
  int index = 0;
  *triple_msg_len = msg1_len + msg2_len + msg3_len + (3 * sizeof(uint16_t));
  *triple_msg = OPENSSL_malloc(*triple_msg_len);
  if (*triple_msg == NULL) {
    return 0;
  }

  ENCODE_UINT16(*triple_msg, msg1_len);
  index += sizeof(uint16_t);
  memcpy(*triple_msg + index, msg1, msg1_len);
  index += msg1_len;

  ENCODE_UINT16(*triple_msg, msg2_len);
  index += sizeof(uint16_t);
  memcpy(*triple_msg + index, msg2, msg2_len);
  index += msg2_len;

  ENCODE_UINT16(*triple_msg, msg3_len);
  index += sizeof(uint16_t);
  memcpy(*triple_msg + index, msg3, msg3_len);

  return 1;
}

/* Decodes triple message returning the classical, PQC and OpenQKD messages:
   msg1_len || msg1 || msg2_len || msg2 || msg3_len || msg3
   msg1 and msg2 are allocated in this function.
   Follows format specified in https://tools.ietf.org/html/draft-stebila-tls-hybrid-design-03
 */
static int OQKD_OQS_decode_triple_message(const unsigned char* triple_msg,
                                     unsigned char** msg1, uint16_t* msg1_len,
                                     unsigned char** msg2, uint16_t* msg2_len,
                                     unsigned char** msg3, uint16_t* msg3_len) {
  int index = 0;
  DECODE_UINT16(*msg1_len, triple_msg);
  index += sizeof(uint16_t);
  *msg1 = OPENSSL_malloc(*msg1_len);
  if (*msg1 == NULL) {
    return 0;
  }
  memcpy(*msg1, triple_msg + index, *msg1_len);
  index += *msg1_len;

  DECODE_UINT16(*msg2_len, triple_msg);
  index += sizeof(uint16_t);
  *msg2 = OPENSSL_malloc(*msg2_len);
  if (*msg2 == NULL) {
    return 0;
  }
  memcpy(*msg2, triple_msg + index, *msg2_len);
  index += *msg2_len;

  DECODE_UINT16(*msg3_len, triple_msg);
  index += sizeof(uint16_t);
  *msg3 = OPENSSL_malloc(*msg3_len);
  if (*msg3 == NULL) {
    return 0;
  }
  memcpy(*msg3, triple_msg + index, *msg3_len);

  return 1;
}