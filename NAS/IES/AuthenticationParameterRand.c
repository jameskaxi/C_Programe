/*
 * Copyright (c) 2015, EURECOM (www.eurecom.fr)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the FreeBSD Project.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#include "../UTIL/TLVEncoder.h"
#include "../UTIL/TLVDecoder.h"
#include "AuthenticationParameterRand.h"

int decode_authentication_parameter_rand(AuthenticationParameterRand *authenticationparameterrand, uint8_t iei, uint8_t *buffer, uint32_t len)
{
  int decoded = 0;
  uint8_t ielen = 16;
  int decode_result;

  if (iei > 0) {
    CHECK_IEI_DECODER(iei, *buffer);
    decoded++;
  }

  if ((decode_result = decode_octet_string(&authenticationparameterrand->rand, ielen, buffer + decoded, len - decoded)) < 0)
    return decode_result;
  else
    decoded += decode_result;

#if defined (NAS_DEBUG)
  dump_authentication_parameter_rand_xml(authenticationparameterrand, iei);
#endif
  return decoded;
}

int encode_authentication_parameter_rand(AuthenticationParameterRand *authenticationparameterrand, uint8_t iei, uint8_t *buffer, uint32_t len)
{
  uint32_t encode_result;
  uint32_t encoded = 0;
  /* Checking IEI and pointer */
  CHECK_PDU_POINTER_AND_LENGTH_ENCODER(buffer, AUTHENTICATION_PARAMETER_RAND_MINIMUM_LENGTH, len);
#if defined (NAS_DEBUG)
  dump_authentication_parameter_rand_xml(authenticationparameterrand, iei);
#endif

  if (iei > 0) {
    *buffer = iei;
    encoded++;
  }

  if ((encode_result = encode_octet_string(&authenticationparameterrand->rand, buffer + encoded, len - encoded)) < 0)
    return encode_result;
  else
    encoded += encode_result;

  return encoded;
}

void dump_authentication_parameter_rand_xml(AuthenticationParameterRand *authenticationparameterrand, uint8_t iei)
{
  printf("<Authentication Parameter Rand>\n");

  if (iei > 0)
    /* Don't display IEI if = 0 */
    printf("    <IEI>0x%X</IEI>\n", iei);

  printf("%s",dump_octet_string_xml(&authenticationparameterrand->rand));
  printf("</Authentication Parameter Rand>\n");
}

