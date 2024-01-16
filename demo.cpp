#include <bits/stdc++.h>
using namespace std;

bool isValidAuthToken(const string& token, const vector<string>& valid_auth_tokens) {
    return find(valid_auth_tokens.begin(), valid_auth_tokens.end(), token) != valid_auth_tokens.end();
}

bool isValidCSRFToken(const string& token) {
    if (token.length() >= 8) {
        return all_of(token.begin(), token.end(), [](char c) {
            return isalnum(c);
        });
    }
    return false;
}

string parseURLParameters(const string& url) {
    stringstream params;
    size_t pos = url.find('?');
    if (pos != string::npos) {
        string parameters = url.substr(pos + 1);
        replace(parameters.begin(), parameters.end(), '&', ' ');
        replace(parameters.begin(), parameters.end(), '=', ' ');

        params << parameters;
    }
    return params.str();
}

vector<string> getResponses(vector<string> valid_auth_tokens, vector<vector<string>> requests) {
    vector<string> result;

    for (const auto& request : requests) {
        if (request.size() < 2) {
            result.push_back("INVALID");
            continue;
        }

        string requestType = request[0];
        string url = request[1];

        size_t tokenPos = url.find("token=");
        if (tokenPos != string::npos) {
            size_t tokenEnd = url.find('&', tokenPos);
            string authToken = (tokenEnd != string::npos) ? url.substr(tokenPos + 6, tokenEnd - tokenPos - 6) : url.substr(tokenPos + 6);

            if (isValidAuthToken(authToken, valid_auth_tokens)) {
                if (requestType == "GET") {
                    result.push_back("VALID," + parseURLParameters(url));
                } else if (requestType == "POST") {
                    size_t csrfPos = url.find("csrf=");
                    if (csrfPos != string::npos) {
                        string csrfToken = url.substr(csrfPos + 5);
                        if (isValidCSRFToken(csrfToken)) {
                            result.push_back("VALID," + parseURLParameters(url));
                        } else {
                            result.push_back("INVALID");
                        }
                    } else {
                        result.push_back("INVALID");
                    }
                }
            } else {
                result.push_back("INVALID");
            }
        } else {
            result.push_back("INVALID");
        }
    }

    return result;
}

int main() {
    vector<string> valid_auth_tokens = {"ah37j2ha483u", "safh34ywb0p5", "ba34wyi8t902"};
    vector<vector<string>> requests = {
        {"GET", "https://example.com/path?token=ah37j2ha483u&param1=value1&param2=value2"},
        {"POST", "https://example.com/path?token=safh34ywb0p5&param1=value1&param2=value2&csrf=abc123def456"},
        {"GET", "https://example.com/path?token=invalidToken&param1=value1&param2=value2"},
        {"POST", "https://example.com/path?token=ba34wyi8t902&param1=value1&param2=value2&csrf=invalidCSRF"},
        {"GET", "https://example.com/pathwithouttoken"}
    };

    vector<string> responses = getResponses(valid_auth_tokens, requests);

    // Displaying responses
    for (const auto& response : responses) {
        cout << response << endl;
    }

    return 0;
}
