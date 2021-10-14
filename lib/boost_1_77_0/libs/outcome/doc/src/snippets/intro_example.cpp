/* Example of Outcome
(C) 2017-2021 Niall Douglas <http://www.nedproductions.biz/> (4 commits), Andrzej Krzemienski <akrzemi1@gmail.com> (3 commits), akrzemi1 <akrzemi1@gmail.com> (1 commit) and Andrzej Krzemieński <akrzemi1@gmail.com> (1 commit)


Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "../../../include/boost/outcome.hpp"
#include <string>
using std::string;
namespace outcome = BOOST_OUTCOME_V2_NAMESPACE;

struct string_view
{
  string_view(const char*) {}
  operator string() { return {}; }
};

struct LibError : std::runtime_error
{
  explicit LibError(std::error_code, string_view s) : std::runtime_error(s) {}
};

void use_string(string) {}

//! [signature]
outcome::result<string> data_from_file(string_view path) noexcept;
//! [signature]

int main() {
//! [inspect]
if (outcome::result<string> rslt = data_from_file("config.cfg"))
  use_string(rslt.value());                   // returns string
else
  throw LibError{rslt.error(), "config.cfg"}; // returns error_code
//! [inspect]
}

//! [implementation]
outcome::result<int> process(const string& content) noexcept;

outcome::result<int> int_from_file(string_view path) noexcept
{
  BOOST_OUTCOME_TRY(auto str, data_from_file(path));
  // if control gets here data_from_file() has succeeded
  return process(str);  // decltype(str) == string
}
//! [implementation]

outcome::result<int> process(const string&) noexcept
{
  return outcome::success(1);
}

outcome::result<string> data_from_file(string_view) noexcept
{
  return outcome::success("1");
}
