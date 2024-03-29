

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from bank.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef bank_1860238290_hpp
#define bank_1860238290_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

static const std::string SELECT_FUND_TOPIC = "SelectFund";

static const std::string SELECT_FUND_TOPIC_ACK = "SelectFundAck";

static const std::string DEPOSIT_TOPIC = "Deposit";

static const std::string WITHDRAW_TOPIC = "Withdraw";

static const std::string TRANSACTION_TOPIC = "Transaction";

static const std::string FUND_DATA_TOPIC = "FundData";

static const std::string MESSAGE_TOPIC = "Message";
enum class FundType {
    SAVINGS, 
    HOUSING
};

NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const FundType& sample);
enum class MessageType {
    SUCCESS, 
    FAILURE, 
    WARNING
};

NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const MessageType& sample);

class NDDSUSERDllExport SelectFund {
  public:
    SelectFund();

    explicit SelectFund(
        const FundType& fund_type);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    SelectFund (SelectFund&&) = default;
    SelectFund& operator=(SelectFund&&) = default;
    SelectFund& operator=(const SelectFund&) = default;
    SelectFund(const SelectFund&) = default;
    #else
    SelectFund(SelectFund&& other_) OMG_NOEXCEPT;  
    SelectFund& operator=(SelectFund&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    FundType& fund_type() OMG_NOEXCEPT {
        return m_fund_type_;
    }

    const FundType& fund_type() const OMG_NOEXCEPT {
        return m_fund_type_;
    }

    void fund_type(const FundType& value) {
        m_fund_type_ = value;
    }

    void fund_type(FundType&& value) {
        m_fund_type_ = std::move(value);
    }

    bool operator == (const SelectFund& other_) const;
    bool operator != (const SelectFund& other_) const;

    void swap(SelectFund& other_) OMG_NOEXCEPT ;

  private:

    FundType m_fund_type_;

};

inline void swap(SelectFund& a, SelectFund& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SelectFund& sample);

class NDDSUSERDllExport SelectFundAck {
  public:
    SelectFundAck();

    explicit SelectFundAck(
        const FundType& fund_type);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    SelectFundAck (SelectFundAck&&) = default;
    SelectFundAck& operator=(SelectFundAck&&) = default;
    SelectFundAck& operator=(const SelectFundAck&) = default;
    SelectFundAck(const SelectFundAck&) = default;
    #else
    SelectFundAck(SelectFundAck&& other_) OMG_NOEXCEPT;  
    SelectFundAck& operator=(SelectFundAck&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    FundType& fund_type() OMG_NOEXCEPT {
        return m_fund_type_;
    }

    const FundType& fund_type() const OMG_NOEXCEPT {
        return m_fund_type_;
    }

    void fund_type(const FundType& value) {
        m_fund_type_ = value;
    }

    void fund_type(FundType&& value) {
        m_fund_type_ = std::move(value);
    }

    bool operator == (const SelectFundAck& other_) const;
    bool operator != (const SelectFundAck& other_) const;

    void swap(SelectFundAck& other_) OMG_NOEXCEPT ;

  private:

    FundType m_fund_type_;

};

inline void swap(SelectFundAck& a, SelectFundAck& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SelectFundAck& sample);

class NDDSUSERDllExport Deposit {
  public:
    Deposit();

    explicit Deposit(
        int32_t amount);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    Deposit (Deposit&&) = default;
    Deposit& operator=(Deposit&&) = default;
    Deposit& operator=(const Deposit&) = default;
    Deposit(const Deposit&) = default;
    #else
    Deposit(Deposit&& other_) OMG_NOEXCEPT;  
    Deposit& operator=(Deposit&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    int32_t& amount() OMG_NOEXCEPT {
        return m_amount_;
    }

    const int32_t& amount() const OMG_NOEXCEPT {
        return m_amount_;
    }

    void amount(int32_t value) {
        m_amount_ = value;
    }

    bool operator == (const Deposit& other_) const;
    bool operator != (const Deposit& other_) const;

    void swap(Deposit& other_) OMG_NOEXCEPT ;

  private:

    int32_t m_amount_;

};

inline void swap(Deposit& a, Deposit& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Deposit& sample);

class NDDSUSERDllExport Withdraw {
  public:
    Withdraw();

    explicit Withdraw(
        int32_t amount);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    Withdraw (Withdraw&&) = default;
    Withdraw& operator=(Withdraw&&) = default;
    Withdraw& operator=(const Withdraw&) = default;
    Withdraw(const Withdraw&) = default;
    #else
    Withdraw(Withdraw&& other_) OMG_NOEXCEPT;  
    Withdraw& operator=(Withdraw&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    int32_t& amount() OMG_NOEXCEPT {
        return m_amount_;
    }

    const int32_t& amount() const OMG_NOEXCEPT {
        return m_amount_;
    }

    void amount(int32_t value) {
        m_amount_ = value;
    }

    bool operator == (const Withdraw& other_) const;
    bool operator != (const Withdraw& other_) const;

    void swap(Withdraw& other_) OMG_NOEXCEPT ;

  private:

    int32_t m_amount_;

};

inline void swap(Withdraw& a, Withdraw& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Withdraw& sample);

class NDDSUSERDllExport Transaction {
  public:
    Transaction();

    Transaction(
        const FundType& fund_type_destination,
        int32_t amount);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    Transaction (Transaction&&) = default;
    Transaction& operator=(Transaction&&) = default;
    Transaction& operator=(const Transaction&) = default;
    Transaction(const Transaction&) = default;
    #else
    Transaction(Transaction&& other_) OMG_NOEXCEPT;  
    Transaction& operator=(Transaction&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    FundType& fund_type_destination() OMG_NOEXCEPT {
        return m_fund_type_destination_;
    }

    const FundType& fund_type_destination() const OMG_NOEXCEPT {
        return m_fund_type_destination_;
    }

    void fund_type_destination(const FundType& value) {
        m_fund_type_destination_ = value;
    }

    void fund_type_destination(FundType&& value) {
        m_fund_type_destination_ = std::move(value);
    }
    int32_t& amount() OMG_NOEXCEPT {
        return m_amount_;
    }

    const int32_t& amount() const OMG_NOEXCEPT {
        return m_amount_;
    }

    void amount(int32_t value) {
        m_amount_ = value;
    }

    bool operator == (const Transaction& other_) const;
    bool operator != (const Transaction& other_) const;

    void swap(Transaction& other_) OMG_NOEXCEPT ;

  private:

    FundType m_fund_type_destination_;
    int32_t m_amount_;

};

inline void swap(Transaction& a, Transaction& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Transaction& sample);

class NDDSUSERDllExport FundData {
  public:
    FundData();

    FundData(
        const FundType& fund_type,
        int32_t amount);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    FundData (FundData&&) = default;
    FundData& operator=(FundData&&) = default;
    FundData& operator=(const FundData&) = default;
    FundData(const FundData&) = default;
    #else
    FundData(FundData&& other_) OMG_NOEXCEPT;  
    FundData& operator=(FundData&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    FundType& fund_type() OMG_NOEXCEPT {
        return m_fund_type_;
    }

    const FundType& fund_type() const OMG_NOEXCEPT {
        return m_fund_type_;
    }

    void fund_type(const FundType& value) {
        m_fund_type_ = value;
    }

    void fund_type(FundType&& value) {
        m_fund_type_ = std::move(value);
    }
    int32_t& amount() OMG_NOEXCEPT {
        return m_amount_;
    }

    const int32_t& amount() const OMG_NOEXCEPT {
        return m_amount_;
    }

    void amount(int32_t value) {
        m_amount_ = value;
    }

    bool operator == (const FundData& other_) const;
    bool operator != (const FundData& other_) const;

    void swap(FundData& other_) OMG_NOEXCEPT ;

  private:

    FundType m_fund_type_;
    int32_t m_amount_;

};

inline void swap(FundData& a, FundData& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const FundData& sample);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
// On Windows, dll-export template instantiations of standard types used by
// other dll-exported types
template class NDDSUSERDllExport std::allocator< int32_t >;
template class NDDSUSERDllExport std::vector< int32_t >;
template class NDDSUSERDllExport std::allocator< std::string >;
template class NDDSUSERDllExport std::vector< std::string >;
#endif
class NDDSUSERDllExport Message {
  public:
    Message();

    Message(
        int64_t date,
        const MessageType& message_type,
        const ::rti::core::bounded_sequence< int32_t, 100L >& literals,
        const ::rti::core::bounded_sequence< std::string, 100L >& data);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    Message (Message&&) = default;
    Message& operator=(Message&&) = default;
    Message& operator=(const Message&) = default;
    Message(const Message&) = default;
    #else
    Message(Message&& other_) OMG_NOEXCEPT;  
    Message& operator=(Message&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    int64_t& date() OMG_NOEXCEPT {
        return m_date_;
    }

    const int64_t& date() const OMG_NOEXCEPT {
        return m_date_;
    }

    void date(int64_t value) {
        m_date_ = value;
    }

    MessageType& message_type() OMG_NOEXCEPT {
        return m_message_type_;
    }

    const MessageType& message_type() const OMG_NOEXCEPT {
        return m_message_type_;
    }

    void message_type(const MessageType& value) {
        m_message_type_ = value;
    }

    void message_type(MessageType&& value) {
        m_message_type_ = std::move(value);
    }
    ::rti::core::bounded_sequence< int32_t, 100L >& literals() OMG_NOEXCEPT {
        return m_literals_;
    }

    const ::rti::core::bounded_sequence< int32_t, 100L >& literals() const OMG_NOEXCEPT {
        return m_literals_;
    }

    void literals(const ::rti::core::bounded_sequence< int32_t, 100L >& value) {
        m_literals_ = value;
    }

    void literals(::rti::core::bounded_sequence< int32_t, 100L >&& value) {
        m_literals_ = std::move(value);
    }
    ::rti::core::bounded_sequence< std::string, 100L >& data() OMG_NOEXCEPT {
        return m_data_;
    }

    const ::rti::core::bounded_sequence< std::string, 100L >& data() const OMG_NOEXCEPT {
        return m_data_;
    }

    void data(const ::rti::core::bounded_sequence< std::string, 100L >& value) {
        m_data_ = value;
    }

    void data(::rti::core::bounded_sequence< std::string, 100L >&& value) {
        m_data_ = std::move(value);
    }

    bool operator == (const Message& other_) const;
    bool operator != (const Message& other_) const;

    void swap(Message& other_) OMG_NOEXCEPT ;

  private:

    int64_t m_date_;
    MessageType m_message_type_;
    ::rti::core::bounded_sequence< int32_t, 100L > m_literals_;
    ::rti::core::bounded_sequence< std::string, 100L > m_data_;

};

inline void swap(Message& a, Message& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Message& sample);

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< SelectFund > {
            NDDSUSERDllExport static std::string value() {
                return "SelectFund";
            }
        };

        template<>
        struct is_topic_type< SelectFund > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< SelectFund > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const SelectFund& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(SelectFund& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(SelectFund& sample);

            NDDSUSERDllExport 
            static void allocate_sample(SelectFund& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< SelectFundAck > {
            NDDSUSERDllExport static std::string value() {
                return "SelectFundAck";
            }
        };

        template<>
        struct is_topic_type< SelectFundAck > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< SelectFundAck > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const SelectFundAck& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(SelectFundAck& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(SelectFundAck& sample);

            NDDSUSERDllExport 
            static void allocate_sample(SelectFundAck& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< Deposit > {
            NDDSUSERDllExport static std::string value() {
                return "Deposit";
            }
        };

        template<>
        struct is_topic_type< Deposit > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< Deposit > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const Deposit& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(Deposit& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(Deposit& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Deposit& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< Withdraw > {
            NDDSUSERDllExport static std::string value() {
                return "Withdraw";
            }
        };

        template<>
        struct is_topic_type< Withdraw > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< Withdraw > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const Withdraw& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(Withdraw& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(Withdraw& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Withdraw& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< Transaction > {
            NDDSUSERDllExport static std::string value() {
                return "Transaction";
            }
        };

        template<>
        struct is_topic_type< Transaction > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< Transaction > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const Transaction& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(Transaction& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(Transaction& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Transaction& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< FundData > {
            NDDSUSERDllExport static std::string value() {
                return "FundData";
            }
        };

        template<>
        struct is_topic_type< FundData > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< FundData > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const FundData& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(FundData& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(FundData& sample);

            NDDSUSERDllExport 
            static void allocate_sample(FundData& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< Message > {
            NDDSUSERDllExport static std::string value() {
                return "Message";
            }
        };

        template<>
        struct is_topic_type< Message > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< Message > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const Message& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(Message& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(Message& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Message& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<FundType>
        {
            static const FundType value;
        };
        template<>
        struct dynamic_type< FundType > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< FundType > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<MessageType>
        {
            static const MessageType value;
        };
        template<>
        struct dynamic_type< MessageType > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< MessageType > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< SelectFund > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< SelectFund > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< SelectFundAck > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< SelectFundAck > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< Deposit > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< Deposit > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< Withdraw > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< Withdraw > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< Transaction > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< Transaction > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< FundData > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< FundData > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< Message > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< Message > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // bank_1860238290_hpp

