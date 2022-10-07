#ifndef USD_NOTICE_FRAMEWORK_PREDICATE_H
#define USD_NOTICE_FRAMEWORK_PREDICATE_H

#include "unf/notice.h"

#include <functional>
#include <vector>
#include <string>

namespace unf {

using CapturePredicateFunc =
    std::function<bool(const BrokerNotice::StageNotice&)>;

class CapturePredicate
{
public:
    CapturePredicate(const CapturePredicateFunc&);

    bool operator()(const BrokerNotice::StageNotice&) const;

    static CapturePredicate Default();
    static CapturePredicate BlockAll();
    static CapturePredicate BlockType(std::string);
    static CapturePredicate BlockTypes(
        const std::vector<std::string>&);

private:
    CapturePredicateFunc _function = nullptr;
};

}  // namespace unf

#endif  // USD_NOTICE_FRAMEWORK_PREDICATE_H
