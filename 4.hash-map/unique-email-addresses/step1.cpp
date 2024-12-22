#include <set>
#include <string>
#include <vector>

class Solution {
public:
  int numUniqueEmails(std::vector<std::string>& emails) {
    const std::vector<std::string> normalized_emails = normalizeEmails(emails);
    const std::set<std::string> unique_emails = std::set(normalized_emails.begin(), normalized_emails.end());
    return unique_emails.size();
  }

private:
  const char AT = '@';
  const char PLUS = '+';
  const char DOT = '.';

  std::vector<std::string> normalizeEmails(const std::vector<std::string>& emails) {
    auto normalizeEmail = [this](const std::string& email) {
      const size_t at_index = email.find(AT, 0);
      const std::string local_name = email.substr(0, at_index);
      const std::string domain_name = email.substr(at_index + 1);
      const std::string normalized_local_name = normalizeLocalName(local_name);
      return normalized_local_name + AT + domain_name;
    };

    std::vector<std::string> normalized_emails(emails.size());
    std::transform(emails.begin(), emails.end(), normalized_emails.begin(), normalizeEmail);
    return normalized_emails;
  }

  /** 
   * Requirements of Local Name:
   * 1. Everything after the first plus '+' in the local name is ignored.
   * 2. Mails which have dots '.' in the local name is forwarded to the same address without the dots.
   */
  std::string normalizeLocalName(const std::string& local_name) {
    std::string name_without_plus = local_name.substr(0, local_name.find(PLUS, 0));
    std::string name_without_plus_and_dot = name_without_plus;
    std::erase(name_without_plus_and_dot, DOT);
    return name_without_plus_and_dot;
  }
};
