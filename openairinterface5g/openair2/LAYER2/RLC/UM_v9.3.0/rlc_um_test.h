/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.0  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

#    ifndef __RLC_UM_TEST_H__
#        define __RLC_UM_TEST_H__
#        ifdef RLC_UM_TEST_C
#            define private_rlc_um_test(x)    x
#            define protected_rlc_um_test(x)  x
#            define public_rlc_um_test(x)     x
#        else
#            ifdef RLC_UM_MODULE
#                define private_rlc_um_test(x)
#                define protected_rlc_um_test(x)  extern x
#                define public_rlc_um_test(x)     extern x
#            else
#                define private_rlc_um_test(x)
#                define protected_rlc_um_test(x)
#                define public_rlc_um_test(x)     extern x
#            endif
#        endif
public_rlc_um_test(rlc_um_entity_t       um_tx;)
public_rlc_um_test(rlc_um_entity_t       um_rx;)

protected_rlc_um_test(void rlc_um_v9_3_0_test_windows_5(void);)
protected_rlc_um_test(void rlc_um_v9_3_0_test_windows_10(void);)
protected_rlc_um_test(void rlc_um_v9_3_0_test_data_conf(module_id_t module_idP, rb_id_t rb_idP, mui_t muiP, rlc_tx_status_t statusP);)
protected_rlc_um_test(void rlc_um_v9_3_0_test_send_sdu(rlc_um_entity_t *um_txP, int sdu_indexP);)
protected_rlc_um_test(void rlc_um_v9_3_0_test_exchange_pdus(rlc_um_entity_t *um_txP,rlc_um_entity_t *um_RxP, uint16_t bytes_txP,uint16_t bytes_rxP);)
protected_rlc_um_test(void rlc_um_v9_3_0_test_exchange_delayed_pdus(rlc_um_entity_t *um_txP, rlc_um_entity_t *um_rxP, uint16_t bytes_txP, uint16_t bytes_rxP, signed int time_tx_delayedP,
                      signed int time_rx_delayedP, int is_frame_incrementedP);)
protected_rlc_um_test(void rlc_um_v9_3_0_buffer_delayed_rx_mac_data_ind(struct mac_data_ind* data_ind_rxP, signed int time_tx_delayedP);)
protected_rlc_um_test(void rlc_um_v9_3_0_test_mac_rlc_loop (struct mac_data_ind *data_indP,  struct mac_data_req *data_requestP, int* drop_countP, int *tx_packetsP, int* dropped_tx_packetsP);)
protected_rlc_um_test(void rlc_um_v9_3_0_test_data_ind (module_id_t module_idP, rb_id_t rb_idP, sdu_size_t sizeP,
                      mem_block_t *sduP);)
protected_rlc_um_test(void rlc_um_v9_3_0_test_tx_rx_10(void);)
protected_rlc_um_test(void rlc_um_v9_3_0_test_tx_rx_5(void);)
public_rlc_um_test(   void rlc_um_v9_3_0_test_print_trace (void);)
public_rlc_um_test(   void rlc_um_v9_3_0_test(void));
#    endif
