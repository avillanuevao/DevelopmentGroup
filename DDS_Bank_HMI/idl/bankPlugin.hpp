

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from bank.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef bankPlugin_1860238142_h
#define bankPlugin_1860238142_h

#include "bank.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
FundTypePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern unsigned int 
FundTypePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
FundTypePlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* ----------------------------------------------------------------------------
Support functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern void
FundTypePluginSupport_print_data(
    const FundType *sample, const char *desc, int indent_level);

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct SelectFund
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct SelectFund)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* SelectFund must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct SelectFund.
*/
typedef  class SelectFund SelectFundKeyHolder;

#define SelectFundPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define SelectFundPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SelectFundPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define SelectFundPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define SelectFundPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define SelectFundPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SelectFundPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SelectFund*
SelectFundPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern SelectFund*
SelectFundPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SelectFund*
SelectFundPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SelectFundPluginSupport_copy_data(
    SelectFund *out,
    const SelectFund *in);

NDDSUSERDllExport extern void 
SelectFundPluginSupport_destroy_data_w_params(
    SelectFund *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
SelectFundPluginSupport_destroy_data_ex(
    SelectFund *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SelectFundPluginSupport_destroy_data(
    SelectFund *sample);

NDDSUSERDllExport extern void 
SelectFundPluginSupport_print_data(
    const SelectFund *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern SelectFund*
SelectFundPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SelectFund*
SelectFundPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
SelectFundPluginSupport_destroy_key_ex(
    SelectFundKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SelectFundPluginSupport_destroy_key(
    SelectFundKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SelectFundPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SelectFundPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
SelectFundPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SelectFundPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
SelectFundPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    SelectFund *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
SelectFundPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SelectFund *out,
    const SelectFund *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
SelectFundPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const SelectFund *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
SelectFundPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SelectFund **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
SelectFundPlugin_deserialize_from_cdr_buffer(
    SelectFund *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
SelectFundPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
SelectFundPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SelectFundPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SelectFundPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SelectFundPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SelectFund ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SelectFundPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SelectFundKeyHolder *key, 
    const SelectFund *instance);

NDDSUSERDllExport extern RTIBool 
SelectFundPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    SelectFund *instance, 
    const SelectFundKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
SelectFundPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SelectFundPlugin_new(void);

NDDSUSERDllExport extern void
SelectFundPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct SelectFundAck
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct SelectFundAck)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* SelectFundAck must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct SelectFundAck.
*/
typedef  class SelectFundAck SelectFundAckKeyHolder;

#define SelectFundAckPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define SelectFundAckPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define SelectFundAckPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define SelectFundAckPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define SelectFundAckPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define SelectFundAckPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define SelectFundAckPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern SelectFundAck*
SelectFundAckPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern SelectFundAck*
SelectFundAckPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SelectFundAck*
SelectFundAckPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
SelectFundAckPluginSupport_copy_data(
    SelectFundAck *out,
    const SelectFundAck *in);

NDDSUSERDllExport extern void 
SelectFundAckPluginSupport_destroy_data_w_params(
    SelectFundAck *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
SelectFundAckPluginSupport_destroy_data_ex(
    SelectFundAck *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SelectFundAckPluginSupport_destroy_data(
    SelectFundAck *sample);

NDDSUSERDllExport extern void 
SelectFundAckPluginSupport_print_data(
    const SelectFundAck *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern SelectFundAck*
SelectFundAckPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern SelectFundAck*
SelectFundAckPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
SelectFundAckPluginSupport_destroy_key_ex(
    SelectFundAckKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
SelectFundAckPluginSupport_destroy_key(
    SelectFundAckKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
SelectFundAckPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
SelectFundAckPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
SelectFundAckPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
SelectFundAckPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
SelectFundAckPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    SelectFundAck *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
SelectFundAckPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SelectFundAck *out,
    const SelectFundAck *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
SelectFundAckPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const SelectFundAck *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
SelectFundAckPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SelectFundAck **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
SelectFundAckPlugin_deserialize_from_cdr_buffer(
    SelectFundAck *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
SelectFundAckPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
SelectFundAckPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
SelectFundAckPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
SelectFundAckPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
SelectFundAckPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SelectFundAck ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
SelectFundAckPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SelectFundAckKeyHolder *key, 
    const SelectFundAck *instance);

NDDSUSERDllExport extern RTIBool 
SelectFundAckPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    SelectFundAck *instance, 
    const SelectFundAckKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
SelectFundAckPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
SelectFundAckPlugin_new(void);

NDDSUSERDllExport extern void
SelectFundAckPlugin_delete(struct PRESTypePlugin *);

#define DepositPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define DepositPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DepositPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define DepositPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DepositPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern Deposit*
DepositPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern Deposit*
DepositPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern Deposit*
DepositPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DepositPluginSupport_copy_data(
    Deposit *out,
    const Deposit *in);

NDDSUSERDllExport extern void 
DepositPluginSupport_destroy_data_w_params(
    Deposit *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DepositPluginSupport_destroy_data_ex(
    Deposit *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DepositPluginSupport_destroy_data(
    Deposit *sample);

NDDSUSERDllExport extern void 
DepositPluginSupport_print_data(
    const Deposit *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DepositPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DepositPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
DepositPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DepositPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
DepositPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    Deposit *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
DepositPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    Deposit *out,
    const Deposit *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
DepositPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const Deposit *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
DepositPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    Deposit **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DepositPlugin_deserialize_from_cdr_buffer(
    Deposit *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
DepositPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
DepositPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DepositPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DepositPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DepositPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    Deposit ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DepositPlugin_new(void);

NDDSUSERDllExport extern void
DepositPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct Withdraw
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct Withdraw)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* Withdraw must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct Withdraw.
*/
typedef  class Withdraw WithdrawKeyHolder;

#define WithdrawPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define WithdrawPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define WithdrawPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define WithdrawPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define WithdrawPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define WithdrawPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define WithdrawPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern Withdraw*
WithdrawPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern Withdraw*
WithdrawPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern Withdraw*
WithdrawPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
WithdrawPluginSupport_copy_data(
    Withdraw *out,
    const Withdraw *in);

NDDSUSERDllExport extern void 
WithdrawPluginSupport_destroy_data_w_params(
    Withdraw *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
WithdrawPluginSupport_destroy_data_ex(
    Withdraw *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
WithdrawPluginSupport_destroy_data(
    Withdraw *sample);

NDDSUSERDllExport extern void 
WithdrawPluginSupport_print_data(
    const Withdraw *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern Withdraw*
WithdrawPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern Withdraw*
WithdrawPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
WithdrawPluginSupport_destroy_key_ex(
    WithdrawKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
WithdrawPluginSupport_destroy_key(
    WithdrawKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
WithdrawPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
WithdrawPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
WithdrawPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
WithdrawPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
WithdrawPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    Withdraw *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
WithdrawPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    Withdraw *out,
    const Withdraw *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
WithdrawPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const Withdraw *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
WithdrawPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    Withdraw **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
WithdrawPlugin_deserialize_from_cdr_buffer(
    Withdraw *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
WithdrawPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
WithdrawPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
WithdrawPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
WithdrawPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
WithdrawPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    Withdraw ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
WithdrawPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    WithdrawKeyHolder *key, 
    const Withdraw *instance);

NDDSUSERDllExport extern RTIBool 
WithdrawPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    Withdraw *instance, 
    const WithdrawKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
WithdrawPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
WithdrawPlugin_new(void);

NDDSUSERDllExport extern void
WithdrawPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct Transaction
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct Transaction)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* Transaction must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct Transaction.
*/
typedef  class Transaction TransactionKeyHolder;

#define TransactionPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define TransactionPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define TransactionPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define TransactionPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define TransactionPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define TransactionPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define TransactionPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern Transaction*
TransactionPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern Transaction*
TransactionPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern Transaction*
TransactionPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
TransactionPluginSupport_copy_data(
    Transaction *out,
    const Transaction *in);

NDDSUSERDllExport extern void 
TransactionPluginSupport_destroy_data_w_params(
    Transaction *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
TransactionPluginSupport_destroy_data_ex(
    Transaction *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
TransactionPluginSupport_destroy_data(
    Transaction *sample);

NDDSUSERDllExport extern void 
TransactionPluginSupport_print_data(
    const Transaction *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern Transaction*
TransactionPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern Transaction*
TransactionPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
TransactionPluginSupport_destroy_key_ex(
    TransactionKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
TransactionPluginSupport_destroy_key(
    TransactionKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
TransactionPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
TransactionPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
TransactionPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
TransactionPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
TransactionPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    Transaction *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
TransactionPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    Transaction *out,
    const Transaction *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
TransactionPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const Transaction *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
TransactionPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    Transaction **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
TransactionPlugin_deserialize_from_cdr_buffer(
    Transaction *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
TransactionPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
TransactionPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
TransactionPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
TransactionPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
TransactionPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    Transaction ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
TransactionPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    TransactionKeyHolder *key, 
    const Transaction *instance);

NDDSUSERDllExport extern RTIBool 
TransactionPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    Transaction *instance, 
    const TransactionKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
TransactionPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
TransactionPlugin_new(void);

NDDSUSERDllExport extern void
TransactionPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct FundData
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct FundData)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* FundData must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct FundData.
*/
typedef  class FundData FundDataKeyHolder;

#define FundDataPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define FundDataPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define FundDataPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define FundDataPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define FundDataPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define FundDataPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define FundDataPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern FundData*
FundDataPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern FundData*
FundDataPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern FundData*
FundDataPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
FundDataPluginSupport_copy_data(
    FundData *out,
    const FundData *in);

NDDSUSERDllExport extern void 
FundDataPluginSupport_destroy_data_w_params(
    FundData *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
FundDataPluginSupport_destroy_data_ex(
    FundData *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
FundDataPluginSupport_destroy_data(
    FundData *sample);

NDDSUSERDllExport extern void 
FundDataPluginSupport_print_data(
    const FundData *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern FundData*
FundDataPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern FundData*
FundDataPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
FundDataPluginSupport_destroy_key_ex(
    FundDataKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
FundDataPluginSupport_destroy_key(
    FundDataKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
FundDataPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
FundDataPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
FundDataPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
FundDataPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
FundDataPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    FundData *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
FundDataPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    FundData *out,
    const FundData *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
FundDataPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const FundData *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
FundDataPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    FundData **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
FundDataPlugin_deserialize_from_cdr_buffer(
    FundData *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
FundDataPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
FundDataPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
FundDataPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
FundDataPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
FundDataPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    FundData ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
FundDataPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    FundDataKeyHolder *key, 
    const FundData *instance);

NDDSUSERDllExport extern RTIBool 
FundDataPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    FundData *instance, 
    const FundDataKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
FundDataPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
FundDataPlugin_new(void);

NDDSUSERDllExport extern void
FundDataPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* bankPlugin_1860238142_h */

