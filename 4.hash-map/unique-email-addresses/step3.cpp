#include <set>
#include <string>
#include <vector>

class Solution {
public:
  int numUniqueEmails(std::vector<std::string>& emails) {
    std::vector<std::string> canonicalized_emails = CanonicalizeEmails(emails);
    std::set<std::string> unique_emails = std::set(canonicalized_emails.begin(), canonicalized_emails.end());
    return unique_emails.size();
  }

private:
  const char AT_SIGN = '@';
  const char PLUS = '+';
  const char DOT = '.';
  std::vector<std::string> CanonicalizeEmails(const std::vector<std::string>& emails) {
    auto CanonicalizeEmail = [this](const std::string& email) {
      size_t at_sign_index = email.find(AT_SIGN);
      std::string local_name = email.substr(0, at_sign_index);
      std::string domain_name = email.substr(at_sign_index + 1);
      std::string canonicalized_local_name = CanonicalizeLocalName(local_name);
      return canonicalized_local_name + AT_SIGN + domain_name;
    };

    std::vector<std::string> canonicalized_emails(emails.size());
    std::transform(emails.begin(), emails.end(), canonicalized_emails.begin(), CanonicalizeEmail);
    return canonicalized_emails;
  }
  std::string CanonicalizeLocalName(const std::string& local_name) {
    std::string name_without_plus = local_name.substr(0, local_name.find(PLUS));
    std::string name_without_plus_and_dot = name_without_plus;
    std::erase(name_without_plus_and_dot, DOT);
    return name_without_plus_and_dot;
  }
};
