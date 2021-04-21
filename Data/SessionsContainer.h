#ifndef UNTITLED_SESSIONSCONTAINER_H
#define UNTITLED_SESSIONSCONTAINER_H

#include "map"
#include "vector"

// Контенер сессий
class SessionsContainer {
private:

    std::vector<std::map<std::string, int>> sessions;

public:


    SessionsContainer() {
        this->sessions.reserve(9);
        for (int i = 0; i < 9; ++i) {
            this->sessions.emplace_back();
        }

    }

    std::vector<std::map<std::string, int>> getVectorOfSessions() {
        return this->sessions;

    };


    ERROR_CODES deleteSession(int session_number, const std::string &subject) {
        --session_number;
        auto temp = this->sessions[session_number].find(subject);
        if (temp != this->sessions[session_number].end()) {
            this->sessions[session_number].erase(subject);
            return OK;
        }
        return NOTHING_FIND;


    }

    ERROR_CODES editSession(int session_number, const std::string &subject, int new_grade) {
        --session_number;
        if ((new_grade > 5) || (new_grade < 2))
            return GRADE_ERROR;
        auto temp = this->sessions[session_number].find(subject);
        if (temp != this->sessions[session_number].end()) {
            temp->second = new_grade;
            return OK;
        } else {
            this->sessions[session_number].insert(std::pair<std::string, int>(subject, new_grade));
            return OK;
        }

    }

    ERROR_CODES addSession(int session_number, const std::string &subject, int grade) {
        --session_number;
        if (this->sessions[session_number].find(subject) == this->sessions[session_number].end()) {
            this->sessions[session_number].insert(this->sessions[session_number].end(),
                                                  std::pair<std::string, int>(subject, grade));

            return OK;
        }
        return ALREADY_EXIST;
    }


};


#endif
