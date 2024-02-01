

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from bank.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "bank.hpp"
#include "bankPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

std::ostream& operator << (std::ostream& o,const FundType& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    switch(sample){
        case FundType::SAVINGS:
        o << "FundType::SAVINGS" << " ";
        break;
        case FundType::HOUSING:
        o << "FundType::HOUSING" << " ";
        break;
    }
    return o;
}

// ---- SelectFund: 

SelectFund::SelectFund() :
    m_fund_type_(FundType::SAVINGS)  {
}   

SelectFund::SelectFund (
    const FundType& fund_type)
    :
        m_fund_type_( fund_type ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
SelectFund::SelectFund(SelectFund&& other_) OMG_NOEXCEPT  :m_fund_type_ (std::move(other_.m_fund_type_))
{
} 

SelectFund& SelectFund::operator=(SelectFund&&  other_) OMG_NOEXCEPT {
    SelectFund tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void SelectFund::swap(SelectFund& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_fund_type_, other_.m_fund_type_);
}  

bool SelectFund::operator == (const SelectFund& other_) const {
    if (m_fund_type_ != other_.m_fund_type_) {
        return false;
    }
    return true;
}
bool SelectFund::operator != (const SelectFund& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const SelectFund& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "fund_type: " << sample.fund_type() ;
    o <<"]";
    return o;
}

// ---- Deposit: 

Deposit::Deposit() :
    m_amount_ (0)  {
}   

Deposit::Deposit (
    int16_t amount)
    :
        m_amount_( amount ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Deposit::Deposit(Deposit&& other_) OMG_NOEXCEPT  :m_amount_ (std::move(other_.m_amount_))
{
} 

Deposit& Deposit::operator=(Deposit&&  other_) OMG_NOEXCEPT {
    Deposit tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void Deposit::swap(Deposit& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_amount_, other_.m_amount_);
}  

bool Deposit::operator == (const Deposit& other_) const {
    if (m_amount_ != other_.m_amount_) {
        return false;
    }
    return true;
}
bool Deposit::operator != (const Deposit& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const Deposit& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "amount: " << sample.amount() ;
    o <<"]";
    return o;
}

// ---- Withdraw: 

Withdraw::Withdraw() :
    m_fund_type_(FundType::SAVINGS) ,
    m_amount_ (0)  {
}   

Withdraw::Withdraw (
    const FundType& fund_type,
    int16_t amount)
    :
        m_fund_type_( fund_type ),
        m_amount_( amount ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Withdraw::Withdraw(Withdraw&& other_) OMG_NOEXCEPT  :m_fund_type_ (std::move(other_.m_fund_type_))
,
m_amount_ (std::move(other_.m_amount_))
{
} 

Withdraw& Withdraw::operator=(Withdraw&&  other_) OMG_NOEXCEPT {
    Withdraw tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void Withdraw::swap(Withdraw& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_fund_type_, other_.m_fund_type_);
    swap(m_amount_, other_.m_amount_);
}  

bool Withdraw::operator == (const Withdraw& other_) const {
    if (m_fund_type_ != other_.m_fund_type_) {
        return false;
    }
    if (m_amount_ != other_.m_amount_) {
        return false;
    }
    return true;
}
bool Withdraw::operator != (const Withdraw& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const Withdraw& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "fund_type: " << sample.fund_type()<<", ";
    o << "amount: " << sample.amount() ;
    o <<"]";
    return o;
}

// ---- Transaction: 

Transaction::Transaction() :
    m_fund_type_origin_(FundType::SAVINGS) ,
    m_fund_type_destination_(FundType::SAVINGS) ,
    m_amount_ (0)  {
}   

Transaction::Transaction (
    const FundType& fund_type_origin,
    const FundType& fund_type_destination,
    int16_t amount)
    :
        m_fund_type_origin_( fund_type_origin ),
        m_fund_type_destination_( fund_type_destination ),
        m_amount_( amount ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Transaction::Transaction(Transaction&& other_) OMG_NOEXCEPT  :m_fund_type_origin_ (std::move(other_.m_fund_type_origin_))
,
m_fund_type_destination_ (std::move(other_.m_fund_type_destination_))
,
m_amount_ (std::move(other_.m_amount_))
{
} 

Transaction& Transaction::operator=(Transaction&&  other_) OMG_NOEXCEPT {
    Transaction tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void Transaction::swap(Transaction& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_fund_type_origin_, other_.m_fund_type_origin_);
    swap(m_fund_type_destination_, other_.m_fund_type_destination_);
    swap(m_amount_, other_.m_amount_);
}  

bool Transaction::operator == (const Transaction& other_) const {
    if (m_fund_type_origin_ != other_.m_fund_type_origin_) {
        return false;
    }
    if (m_fund_type_destination_ != other_.m_fund_type_destination_) {
        return false;
    }
    if (m_amount_ != other_.m_amount_) {
        return false;
    }
    return true;
}
bool Transaction::operator != (const Transaction& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const Transaction& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "fund_type_origin: " << sample.fund_type_origin()<<", ";
    o << "fund_type_destination: " << sample.fund_type_destination()<<", ";
    o << "amount: " << sample.amount() ;
    o <<"]";
    return o;
}

// ---- FundData: 

FundData::FundData() :
    m_fund_type_(FundType::SAVINGS) ,
    m_amount_ (0)  {
}   

FundData::FundData (
    const FundType& fund_type,
    int16_t amount)
    :
        m_fund_type_( fund_type ),
        m_amount_( amount ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
FundData::FundData(FundData&& other_) OMG_NOEXCEPT  :m_fund_type_ (std::move(other_.m_fund_type_))
,
m_amount_ (std::move(other_.m_amount_))
{
} 

FundData& FundData::operator=(FundData&&  other_) OMG_NOEXCEPT {
    FundData tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void FundData::swap(FundData& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_fund_type_, other_.m_fund_type_);
    swap(m_amount_, other_.m_amount_);
}  

bool FundData::operator == (const FundData& other_) const {
    if (m_fund_type_ != other_.m_fund_type_) {
        return false;
    }
    if (m_amount_ != other_.m_amount_) {
        return false;
    }
    return true;
}
bool FundData::operator != (const FundData& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const FundData& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "fund_type: " << sample.fund_type()<<", ";
    o << "amount: " << sample.amount() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        const FundType default_enumerator<FundType>::value = FundType::SAVINGS;
        template<>
        struct native_type_code< FundType > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member FundType_g_tc_members[2]=
                {

                    {
                        (char *)"SAVINGS",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(FundType::SAVINGS), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"HOUSING",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(FundType::HOUSING), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode FundType_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"FundType", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        FundType_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for FundType*/

                if (is_initialized) {
                    return &FundType_g_tc;
                }

                FundType_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                FundType_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                FundType_g_tc._data._annotations._defaultValue._u.long_value = 0;

                FundType_g_tc._data._sampleAccessInfo = sample_access_info();
                FundType_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &FundType_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo FundType_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo FundType_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &FundType_g_sampleAccessInfo;
                }

                FundType_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                FundType_g_sampleAccessInfo.memberAccessInfos = 
                FundType_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(FundType);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        FundType_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        FundType_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                FundType_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                FundType_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< FundType >;

                FundType_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &FundType_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin FundType_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &FundType_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< FundType >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< FundType >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< SelectFund > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member SelectFund_g_tc_members[1]=
                {

                    {
                        (char *)"fund_type",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode SelectFund_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"SelectFund", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        SelectFund_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for SelectFund*/

                if (is_initialized) {
                    return &SelectFund_g_tc;
                }

                SelectFund_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                SelectFund_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< FundType>::get().native();

                /* Initialize the values for member annotations. */
                SelectFund_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                SelectFund_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                SelectFund_g_tc._data._sampleAccessInfo = sample_access_info();
                SelectFund_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &SelectFund_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                SelectFund *sample;

                static RTIXCdrMemberAccessInfo SelectFund_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo SelectFund_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &SelectFund_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    SelectFund);
                if (sample == NULL) {
                    return NULL;
                }

                SelectFund_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->fund_type() - (char *)sample);

                SelectFund_g_sampleAccessInfo.memberAccessInfos = 
                SelectFund_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(SelectFund);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        SelectFund_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        SelectFund_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                SelectFund_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                SelectFund_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< SelectFund >;

                SelectFund_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &SelectFund_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin SelectFund_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &SelectFund_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< SelectFund >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< SelectFund >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< Deposit > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Deposit_g_tc_members[1]=
                {

                    {
                        (char *)"amount",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Deposit_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Deposit", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        Deposit_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Deposit*/

                if (is_initialized) {
                    return &Deposit_g_tc;
                }

                Deposit_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                Deposit_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                /* Initialize the values for member annotations. */
                Deposit_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                Deposit_g_tc_members[0]._annotations._defaultValue._u.short_value = 0;
                Deposit_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                Deposit_g_tc_members[0]._annotations._minValue._u.short_value = RTIXCdrShort_MIN;
                Deposit_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                Deposit_g_tc_members[0]._annotations._maxValue._u.short_value = RTIXCdrShort_MAX;

                Deposit_g_tc._data._sampleAccessInfo = sample_access_info();
                Deposit_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &Deposit_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                Deposit *sample;

                static RTIXCdrMemberAccessInfo Deposit_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Deposit_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Deposit_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    Deposit);
                if (sample == NULL) {
                    return NULL;
                }

                Deposit_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->amount() - (char *)sample);

                Deposit_g_sampleAccessInfo.memberAccessInfos = 
                Deposit_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(Deposit);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Deposit_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Deposit_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Deposit_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Deposit_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< Deposit >;

                Deposit_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Deposit_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Deposit_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Deposit_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< Deposit >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< Deposit >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< Withdraw > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Withdraw_g_tc_members[2]=
                {

                    {
                        (char *)"fund_type",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"amount",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Withdraw_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Withdraw", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        Withdraw_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Withdraw*/

                if (is_initialized) {
                    return &Withdraw_g_tc;
                }

                Withdraw_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                Withdraw_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< FundType>::get().native();
                Withdraw_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                /* Initialize the values for member annotations. */
                Withdraw_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Withdraw_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                Withdraw_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                Withdraw_g_tc_members[1]._annotations._defaultValue._u.short_value = 0;
                Withdraw_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                Withdraw_g_tc_members[1]._annotations._minValue._u.short_value = RTIXCdrShort_MIN;
                Withdraw_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                Withdraw_g_tc_members[1]._annotations._maxValue._u.short_value = RTIXCdrShort_MAX;

                Withdraw_g_tc._data._sampleAccessInfo = sample_access_info();
                Withdraw_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &Withdraw_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                Withdraw *sample;

                static RTIXCdrMemberAccessInfo Withdraw_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Withdraw_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Withdraw_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    Withdraw);
                if (sample == NULL) {
                    return NULL;
                }

                Withdraw_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->fund_type() - (char *)sample);

                Withdraw_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->amount() - (char *)sample);

                Withdraw_g_sampleAccessInfo.memberAccessInfos = 
                Withdraw_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(Withdraw);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Withdraw_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Withdraw_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Withdraw_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Withdraw_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< Withdraw >;

                Withdraw_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Withdraw_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Withdraw_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Withdraw_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< Withdraw >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< Withdraw >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< Transaction > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Transaction_g_tc_members[3]=
                {

                    {
                        (char *)"fund_type_origin",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"fund_type_destination",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"amount",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode Transaction_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Transaction", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        Transaction_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Transaction*/

                if (is_initialized) {
                    return &Transaction_g_tc;
                }

                Transaction_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                Transaction_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< FundType>::get().native();
                Transaction_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< FundType>::get().native();
                Transaction_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                /* Initialize the values for member annotations. */
                Transaction_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Transaction_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                Transaction_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Transaction_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

                Transaction_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                Transaction_g_tc_members[2]._annotations._defaultValue._u.short_value = 0;
                Transaction_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                Transaction_g_tc_members[2]._annotations._minValue._u.short_value = RTIXCdrShort_MIN;
                Transaction_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                Transaction_g_tc_members[2]._annotations._maxValue._u.short_value = RTIXCdrShort_MAX;

                Transaction_g_tc._data._sampleAccessInfo = sample_access_info();
                Transaction_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &Transaction_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                Transaction *sample;

                static RTIXCdrMemberAccessInfo Transaction_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Transaction_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Transaction_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    Transaction);
                if (sample == NULL) {
                    return NULL;
                }

                Transaction_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->fund_type_origin() - (char *)sample);

                Transaction_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->fund_type_destination() - (char *)sample);

                Transaction_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->amount() - (char *)sample);

                Transaction_g_sampleAccessInfo.memberAccessInfos = 
                Transaction_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(Transaction);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Transaction_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Transaction_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Transaction_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Transaction_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< Transaction >;

                Transaction_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Transaction_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Transaction_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &Transaction_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< Transaction >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< Transaction >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< FundData > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member FundData_g_tc_members[2]=
                {

                    {
                        (char *)"fund_type",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"amount",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode FundData_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"FundData", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        FundData_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for FundData*/

                if (is_initialized) {
                    return &FundData_g_tc;
                }

                FundData_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                FundData_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< FundType>::get().native();
                FundData_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                /* Initialize the values for member annotations. */
                FundData_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                FundData_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                FundData_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                FundData_g_tc_members[1]._annotations._defaultValue._u.short_value = 0;
                FundData_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                FundData_g_tc_members[1]._annotations._minValue._u.short_value = RTIXCdrShort_MIN;
                FundData_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                FundData_g_tc_members[1]._annotations._maxValue._u.short_value = RTIXCdrShort_MAX;

                FundData_g_tc._data._sampleAccessInfo = sample_access_info();
                FundData_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &FundData_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                FundData *sample;

                static RTIXCdrMemberAccessInfo FundData_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo FundData_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &FundData_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    FundData);
                if (sample == NULL) {
                    return NULL;
                }

                FundData_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->fund_type() - (char *)sample);

                FundData_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->amount() - (char *)sample);

                FundData_g_sampleAccessInfo.memberAccessInfos = 
                FundData_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(FundData);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        FundData_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        FundData_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                FundData_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                FundData_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< FundData >;

                FundData_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &FundData_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin FundData_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &FundData_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< FundData >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< FundData >::get())));
        }

    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< SelectFund >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                SelectFundPlugin_new,
                SelectFundPlugin_delete);
        }

        std::vector<char>& topic_type_support< SelectFund >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const SelectFund& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = SelectFundPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = SelectFundPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< SelectFund >::from_cdr_buffer(SelectFund& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = SelectFundPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create SelectFund from cdr buffer");
        }

        void topic_type_support< SelectFund >::reset_sample(SelectFund& sample) 
        {
            sample.fund_type(FundType::SAVINGS);
        }

        void topic_type_support< SelectFund >::allocate_sample(SelectFund& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.fund_type(),  -1, -1);
        }

        void topic_type_support< Deposit >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                DepositPlugin_new,
                DepositPlugin_delete);
        }

        std::vector<char>& topic_type_support< Deposit >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const Deposit& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DepositPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DepositPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< Deposit >::from_cdr_buffer(Deposit& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DepositPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create Deposit from cdr buffer");
        }

        void topic_type_support< Deposit >::reset_sample(Deposit& sample) 
        {
            sample.amount(0);
        }

        void topic_type_support< Deposit >::allocate_sample(Deposit& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }

        void topic_type_support< Withdraw >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                WithdrawPlugin_new,
                WithdrawPlugin_delete);
        }

        std::vector<char>& topic_type_support< Withdraw >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const Withdraw& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = WithdrawPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = WithdrawPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< Withdraw >::from_cdr_buffer(Withdraw& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = WithdrawPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create Withdraw from cdr buffer");
        }

        void topic_type_support< Withdraw >::reset_sample(Withdraw& sample) 
        {
            sample.fund_type(FundType::SAVINGS);
            sample.amount(0);
        }

        void topic_type_support< Withdraw >::allocate_sample(Withdraw& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.fund_type(),  -1, -1);
        }

        void topic_type_support< Transaction >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                TransactionPlugin_new,
                TransactionPlugin_delete);
        }

        std::vector<char>& topic_type_support< Transaction >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const Transaction& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = TransactionPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = TransactionPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< Transaction >::from_cdr_buffer(Transaction& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = TransactionPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create Transaction from cdr buffer");
        }

        void topic_type_support< Transaction >::reset_sample(Transaction& sample) 
        {
            sample.fund_type_origin(FundType::SAVINGS);
            sample.fund_type_destination(FundType::SAVINGS);
            sample.amount(0);
        }

        void topic_type_support< Transaction >::allocate_sample(Transaction& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.fund_type_origin(),  -1, -1);
            ::rti::topic::allocate_sample(sample.fund_type_destination(),  -1, -1);
        }

        void topic_type_support< FundData >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                FundDataPlugin_new,
                FundDataPlugin_delete);
        }

        std::vector<char>& topic_type_support< FundData >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const FundData& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = FundDataPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = FundDataPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< FundData >::from_cdr_buffer(FundData& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = FundDataPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create FundData from cdr buffer");
        }

        void topic_type_support< FundData >::reset_sample(FundData& sample) 
        {
            sample.fund_type(FundType::SAVINGS);
            sample.amount(0);
        }

        void topic_type_support< FundData >::allocate_sample(FundData& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.fund_type(),  -1, -1);
        }

    }
}  

