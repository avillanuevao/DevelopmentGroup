

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

std::ostream& operator << (std::ostream& o,const MessageType& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    switch(sample){
        case MessageType::SUCCESS:
        o << "MessageType::SUCCESS" << " ";
        break;
        case MessageType::FAILURE:
        o << "MessageType::FAILURE" << " ";
        break;
        case MessageType::WARNING:
        o << "MessageType::WARNING" << " ";
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

// ---- SelectFundAck: 

SelectFundAck::SelectFundAck() :
    m_fund_type_(FundType::SAVINGS)  {
}   

SelectFundAck::SelectFundAck (
    const FundType& fund_type)
    :
        m_fund_type_( fund_type ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
SelectFundAck::SelectFundAck(SelectFundAck&& other_) OMG_NOEXCEPT  :m_fund_type_ (std::move(other_.m_fund_type_))
{
} 

SelectFundAck& SelectFundAck::operator=(SelectFundAck&&  other_) OMG_NOEXCEPT {
    SelectFundAck tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void SelectFundAck::swap(SelectFundAck& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_fund_type_, other_.m_fund_type_);
}  

bool SelectFundAck::operator == (const SelectFundAck& other_) const {
    if (m_fund_type_ != other_.m_fund_type_) {
        return false;
    }
    return true;
}
bool SelectFundAck::operator != (const SelectFundAck& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const SelectFundAck& sample)
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
    int32_t amount)
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
    m_amount_ (0)  {
}   

Withdraw::Withdraw (
    int32_t amount)
    :
        m_amount_( amount ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Withdraw::Withdraw(Withdraw&& other_) OMG_NOEXCEPT  :m_amount_ (std::move(other_.m_amount_))
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
    swap(m_amount_, other_.m_amount_);
}  

bool Withdraw::operator == (const Withdraw& other_) const {
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
    o << "amount: " << sample.amount() ;
    o <<"]";
    return o;
}

// ---- Transaction: 

Transaction::Transaction() :
    m_fund_type_destination_(FundType::SAVINGS) ,
    m_amount_ (0)  {
}   

Transaction::Transaction (
    const FundType& fund_type_destination,
    int32_t amount)
    :
        m_fund_type_destination_( fund_type_destination ),
        m_amount_( amount ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Transaction::Transaction(Transaction&& other_) OMG_NOEXCEPT  :m_fund_type_destination_ (std::move(other_.m_fund_type_destination_))
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
    swap(m_fund_type_destination_, other_.m_fund_type_destination_);
    swap(m_amount_, other_.m_amount_);
}  

bool Transaction::operator == (const Transaction& other_) const {
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
    int32_t amount)
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

// ---- Message: 

Message::Message() :
    m_date_ (0ll) ,
    m_message_type_(MessageType::SUCCESS)  {
}   

Message::Message (
    int64_t date,
    const MessageType& message_type,
    const ::rti::core::bounded_sequence< int32_t, 100L >& literals,
    const ::rti::core::bounded_sequence< std::string, 100L >& data)
    :
        m_date_( date ),
        m_message_type_( message_type ),
        m_literals_( literals ),
        m_data_( data ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Message::Message(Message&& other_) OMG_NOEXCEPT  :m_date_ (std::move(other_.m_date_))
,
m_message_type_ (std::move(other_.m_message_type_))
,
m_literals_ (std::move(other_.m_literals_))
,
m_data_ (std::move(other_.m_data_))
{
} 

Message& Message::operator=(Message&&  other_) OMG_NOEXCEPT {
    Message tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void Message::swap(Message& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_date_, other_.m_date_);
    swap(m_message_type_, other_.m_message_type_);
    swap(m_literals_, other_.m_literals_);
    swap(m_data_, other_.m_data_);
}  

bool Message::operator == (const Message& other_) const {
    if (m_date_ != other_.m_date_) {
        return false;
    }
    if (m_message_type_ != other_.m_message_type_) {
        return false;
    }
    if (m_literals_ != other_.m_literals_) {
        return false;
    }
    if (m_data_ != other_.m_data_) {
        return false;
    }
    return true;
}
bool Message::operator != (const Message& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const Message& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "date: " << sample.date()<<", ";
    o << "message_type: " << sample.message_type()<<", ";
    o << "literals: " << sample.literals()<<", ";
    o << "data: " << sample.data() ;
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
        const MessageType default_enumerator<MessageType>::value = MessageType::SUCCESS;
        template<>
        struct native_type_code< MessageType > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member MessageType_g_tc_members[3]=
                {

                    {
                        (char *)"SUCCESS",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(MessageType::SUCCESS), 
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
                        (char *)"FAILURE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(MessageType::FAILURE), 
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
                        (char *)"WARNING",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(MessageType::WARNING), 
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

                static DDS_TypeCode MessageType_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"MessageType", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        MessageType_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for MessageType*/

                if (is_initialized) {
                    return &MessageType_g_tc;
                }

                MessageType_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                MessageType_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                MessageType_g_tc._data._annotations._defaultValue._u.long_value = 0;

                MessageType_g_tc._data._sampleAccessInfo = sample_access_info();
                MessageType_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &MessageType_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo MessageType_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo MessageType_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &MessageType_g_sampleAccessInfo;
                }

                MessageType_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                MessageType_g_sampleAccessInfo.memberAccessInfos = 
                MessageType_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(MessageType);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        MessageType_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        MessageType_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                MessageType_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                MessageType_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< MessageType >;

                MessageType_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &MessageType_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin MessageType_g_typePlugin = 
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

                return &MessageType_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< MessageType >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< MessageType >::get())));
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
        struct native_type_code< SelectFundAck > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member SelectFundAck_g_tc_members[1]=
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

                static DDS_TypeCode SelectFundAck_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"SelectFundAck", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        SelectFundAck_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for SelectFundAck*/

                if (is_initialized) {
                    return &SelectFundAck_g_tc;
                }

                SelectFundAck_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                SelectFundAck_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< FundType>::get().native();

                /* Initialize the values for member annotations. */
                SelectFundAck_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                SelectFundAck_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                SelectFundAck_g_tc._data._sampleAccessInfo = sample_access_info();
                SelectFundAck_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &SelectFundAck_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                SelectFundAck *sample;

                static RTIXCdrMemberAccessInfo SelectFundAck_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo SelectFundAck_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &SelectFundAck_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    SelectFundAck);
                if (sample == NULL) {
                    return NULL;
                }

                SelectFundAck_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->fund_type() - (char *)sample);

                SelectFundAck_g_sampleAccessInfo.memberAccessInfos = 
                SelectFundAck_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(SelectFundAck);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        SelectFundAck_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        SelectFundAck_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                SelectFundAck_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                SelectFundAck_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< SelectFundAck >;

                SelectFundAck_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &SelectFundAck_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin SelectFundAck_g_typePlugin = 
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

                return &SelectFundAck_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< SelectFundAck >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< SelectFundAck >::get())));
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

                Deposit_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                /* Initialize the values for member annotations. */
                Deposit_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                Deposit_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                Deposit_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                Deposit_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                Deposit_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                Deposit_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

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

                static DDS_TypeCode_Member Withdraw_g_tc_members[1]=
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
                        1, /* Number of members */
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

                Withdraw_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                /* Initialize the values for member annotations. */
                Withdraw_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                Withdraw_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                Withdraw_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                Withdraw_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                Withdraw_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                Withdraw_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                Withdraw_g_tc._data._sampleAccessInfo = sample_access_info();
                Withdraw_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &Withdraw_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                Withdraw *sample;

                static RTIXCdrMemberAccessInfo Withdraw_g_memberAccessInfos[1] =
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

                static DDS_TypeCode_Member Transaction_g_tc_members[2]=
                {

                    {
                        (char *)"fund_type_destination",/* Member name */
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
                        2, /* Number of members */
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
                Transaction_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                /* Initialize the values for member annotations. */
                Transaction_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Transaction_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                Transaction_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                Transaction_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
                Transaction_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                Transaction_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                Transaction_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                Transaction_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                Transaction_g_tc._data._sampleAccessInfo = sample_access_info();
                Transaction_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &Transaction_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                Transaction *sample;

                static RTIXCdrMemberAccessInfo Transaction_g_memberAccessInfos[2] =
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
                (RTIXCdrUnsignedLong) ((char *)&sample->fund_type_destination() - (char *)sample);

                Transaction_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
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
                FundData_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                /* Initialize the values for member annotations. */
                FundData_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                FundData_g_tc_members[0]._annotations._defaultValue._u.enumerated_value = 0;

                FundData_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                FundData_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
                FundData_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                FundData_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                FundData_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                FundData_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

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

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< Message > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode Message_g_tc_literals_sequence;
                static DDS_TypeCode Message_g_tc_data_string;
                static DDS_TypeCode Message_g_tc_data_sequence;

                static DDS_TypeCode_Member Message_g_tc_members[4]=
                {

                    {
                        (char *)"date",/* Member name */
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
                    }, 
                    {
                        (char *)"message_type",/* Member name */
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
                        (char *)"literals",/* Member name */
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
                    }, 
                    {
                        (char *)"data",/* Member name */
                        {
                            3,/* Representation ID */
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

                static DDS_TypeCode Message_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Message", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        Message_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for Message*/

                if (is_initialized) {
                    return &Message_g_tc;
                }

                Message_g_tc_literals_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< int32_t, 100L > >((100L));
                Message_g_tc_data_string = initialize_string_typecode((255L));
                Message_g_tc_data_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< std::string, 100L > >((100L));

                Message_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                Message_g_tc_literals_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                Message_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&Message_g_tc_data_string;
                Message_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_longlong;
                Message_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< MessageType>::get().native();
                Message_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& Message_g_tc_literals_sequence;
                Message_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& Message_g_tc_data_sequence;

                /* Initialize the values for member annotations. */
                Message_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONGLONG;
                Message_g_tc_members[0]._annotations._defaultValue._u.long_long_value = 0ll;
                Message_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONGLONG;
                Message_g_tc_members[0]._annotations._minValue._u.long_long_value = RTIXCdrLongLong_MIN;
                Message_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONGLONG;
                Message_g_tc_members[0]._annotations._maxValue._u.long_long_value = RTIXCdrLongLong_MAX;

                Message_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                Message_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

                Message_g_tc._data._sampleAccessInfo = sample_access_info();
                Message_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &Message_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                Message *sample;

                static RTIXCdrMemberAccessInfo Message_g_memberAccessInfos[4] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo Message_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &Message_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    Message);
                if (sample == NULL) {
                    return NULL;
                }

                Message_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->date() - (char *)sample);

                Message_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->message_type() - (char *)sample);

                Message_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->literals() - (char *)sample);

                Message_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->data() - (char *)sample);

                Message_g_sampleAccessInfo.memberAccessInfos = 
                Message_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(Message);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        Message_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        Message_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                Message_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                Message_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< Message >;

                Message_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &Message_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin Message_g_typePlugin = 
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

                return &Message_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< Message >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< Message >::get())));
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

        void topic_type_support< SelectFundAck >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                SelectFundAckPlugin_new,
                SelectFundAckPlugin_delete);
        }

        std::vector<char>& topic_type_support< SelectFundAck >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const SelectFundAck& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = SelectFundAckPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = SelectFundAckPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< SelectFundAck >::from_cdr_buffer(SelectFundAck& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = SelectFundAckPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create SelectFundAck from cdr buffer");
        }

        void topic_type_support< SelectFundAck >::reset_sample(SelectFundAck& sample) 
        {
            sample.fund_type(FundType::SAVINGS);
        }

        void topic_type_support< SelectFundAck >::allocate_sample(SelectFundAck& sample, int, int) 
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
            sample.amount(0);
        }

        void topic_type_support< Withdraw >::allocate_sample(Withdraw& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
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
            sample.fund_type_destination(FundType::SAVINGS);
            sample.amount(0);
        }

        void topic_type_support< Transaction >::allocate_sample(Transaction& sample, int, int) 
        {
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

        void topic_type_support< Message >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                MessagePlugin_new,
                MessagePlugin_delete);
        }

        std::vector<char>& topic_type_support< Message >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const Message& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = MessagePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = MessagePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< Message >::from_cdr_buffer(Message& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = MessagePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create Message from cdr buffer");
        }

        void topic_type_support< Message >::reset_sample(Message& sample) 
        {
            sample.date(0ll);
            sample.message_type(MessageType::SUCCESS);
            ::rti::topic::reset_sample(sample.literals());
            ::rti::topic::reset_sample(sample.data());
        }

        void topic_type_support< Message >::allocate_sample(Message& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.message_type(),  -1, -1);
            ::rti::topic::allocate_sample(sample.literals(),  100L, -1);
            ::rti::topic::allocate_sample(sample.data(),  100L, 255L);
        }

    }
}  

