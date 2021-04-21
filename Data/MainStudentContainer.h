//
// Created by tiramisu on 11.04.2021.
//

#ifndef UNTITLED_MAINSTUDENTCONTAINER_H
#define UNTITLED_MAINSTUDENTCONTAINER_H

class MainStudentContainer : public StudentsContainer, public Savable {
private:
    int student_counter = 0;
private:
    // запрет вызова поиска.
    void *FindStudents(const std::string &request) override {}


public:





    ERROR_CODES NewStudent(Student *student) {
        student->id = student_counter;
        ++student_counter;
        this->students.push_back(student);
        return OK;
    }


    ERROR_CODES DeleteStudent(int student_number) {
        if (student_number < student_counter) {
            students[student_number]->id = -1;
            students.erase(students.begin()+student_number);
            --student_counter;
            return OK;
        } else
            return OUT_OF_RANGE;

    };



    // принимает имя файла, где в конце будет поставлен номер студента
    ERROR_CODES save(std::string filename) override {
        int end = std::remove((filename+"0").c_str());
        for (int i =1; end ==0; ++i){
            end = std::remove((filename+std::to_string(i)).c_str());
        }


        for (int i = 0, k = 0; k < students.size(); ++i, ++k) {
            if (students[i]->save(filename + std::to_string(i))==NOT_SAVED)
                --i;
        }
        return OK;
    };

    // принимает имя файла, где в конце будет поставлен номер студента
    ERROR_CODES load(std::string filename, bool is_need_return_error = false) override {
        ERROR_CODES error = OK;
        for (int i = 0; error == OK; ++i) {
            auto *student = new Student();
            error = student->load(filename + std::to_string(i), true);
            if (error == OK)
                this->NewStudent(student);
        }
    }

    friend std::ostream &operator<<(std::ostream &out, MainStudentContainer &studentsManager);



};


std::ostream &operator<<(std::ostream &out, MainStudentContainer &studentsManager) {

    for (auto &item: studentsManager.students) {
             out << *item;
    }


    return out;
}



#endif //UNTITLED_MAINSTUDENTCONTAINER_H
