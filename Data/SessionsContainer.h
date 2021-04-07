//
// Created by tiramisu on 06.04.2021.
//

#ifndef UNTITLED_SESSIONSCONTAINER_H
#define UNTITLED_SESSIONSCONTAINER_H

#include "map"
#include "vector"

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


    int getSubjectGrade(const int &session_number, const std::string &subject) {
        auto temp = this->sessions[session_number].find(subject);
        if (temp != this->sessions[session_number].end())
            return this->sessions[session_number].find(subject)->second;
        else
            return -1;

    }

    ERROR_CODES deleteSession(const int &session_number, const std::string &subject) {
        auto temp = this->sessions[session_number].find(subject);
        if (temp != this->sessions[session_number].end()) {
            this->sessions[session_number].erase(subject);
            return OK;
        }
        return NOTHING_FIND;


    }

    ERROR_CODES editSession(const int &session_number, const std::string &subject, int new_grade) {
        auto temp = this->sessions[session_number].find(subject);
        if (temp != this->sessions[session_number].end()) {
            temp->second = new_grade;
            return OK;
        } else {
            this->sessions[session_number].insert(std::pair<std::string, int>(subject, new_grade));
            return OK;
        }

    }

    ERROR_CODES addSession(const int &session_number, const std::string subject, int grade) {
        if (this->sessions[session_number].find(subject) == this->sessions[session_number].end()) {
            this->sessions[session_number].insert(this->sessions[session_number].end(),
                                                  std::pair<std::string, int>(subject, grade));

            return OK;
        }
        return ALREADY_EXIST;
    }


};


#endif //UNTITLED_SESSIONSCONTAINER_H