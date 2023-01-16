#include <iostream>
#include <vector>

using namespace std;

class AbstractSubject {
    protected:
        string SubjectName;
        string SubjectDuration;
        
    public:
        string StartDate;

        // setter
        void setSubjectName(string SubjectName){
            this->SubjectName = SubjectName;
        }

        void setSubjectDuration(string SubjectDuration){
            this->SubjectDuration = SubjectDuration;
        }

        // getter
        string getSubjcetName(){
            return SubjectName;
        }

        string getSubjectDuration(){
            return SubjectDuration;
        }
};

class SkillWillSubject: public AbstractSubject {
    private:
        string LastLectureName;
        
    public:
        SkillWillSubject(string SubjectName, string SubjectDuration, string StartDate, string LastLectureName){
            this->SubjectName = SubjectName;
            this->SubjectDuration = SubjectDuration;
            this->StartDate = StartDate;
        }

        // setter
        void setLastLectureName(string LastLectureName){
            this->LastLectureName = LastLectureName;
        }

        // getter
        string getLastLectureName(){
            return LastLectureName;
        }
};

class AbstractLecturer {
    protected:
        string Name;
        string Surname;
        string SubjectName;
        
    public:
    
        void conductingLecture(){
            cout << "Lecturer is conducting a Lecture" << endl;
        }

        // setter
        void setName(string Name){
            this->Name = Name;
        }

        void setSurname(string Surname){
            this->Surname = Surname;
        }

        void setSubjcetName(string SubjectName){
            this->SubjectName = SubjectName;
        }

        // getter
        string getName(){
            return Name;
        }

        string getSurname(){
            return Surname;
        }

        string getSubjcetName(){
            return SubjectName;
        }
};

class SkillWillLecturer: public AbstractLecturer {
    private:
        string Chapter;
        string Level;
        AbstractSubject date;
    
    public:
        
        SkillWillLecturer(string Name, string Surname, string SubjectName, string Chapter, string Level, AbstractSubject Date){
            this->Name = Name;
            this->Surname = Surname;
            this->SubjectName = SubjectName;
            this->Chapter = Chapter;
            this->Level = Level;
            this->date = Date;
        }
        
        void conductingLecture(string chapter, string startdate){
            if(chapter == Chapter && startdate == date.StartDate){
                cout << Name << " " << Surname << endl;
                cout << endl;
            } else {
                cout << "No exact information" << endl;
            }
        }

        // setter
        void setChapter(string Chapter){
            this->Chapter = Chapter;
        }

        void setLevel(string Level){
            this->Level = Level;
        }

        // getter
        string getChapter(){
            return Chapter;
        }

        string getLevel(){
            return Level;
        }
};

class AbstractStudent {
    protected:
        string Name;
        string Surname;
        int Age;
        string SubjectName;
        
    public:
        
        void attendLecture(){
            cout << "Student attends the lecture" << endl;
        };

        // setter
        void setName(string Name){
            this->Name = Name;
        }

        void setSurname(string Surname){
            this->Surname = Surname;
        }

        void setAge(int Age){
            this->Age = Age;
        }

        void setSubjcetName(string SubjectName){
            this->SubjectName = SubjectName;
        }

        // getter
        string getName(){
            return Name;
        }

        string getSurname(){
            return Surname;
        }

        int getAge(){
            return Age;
        }

        string getSubjcetName(){
            return SubjectName;
        }
};

class SkillWillStudent: public AbstractStudent {
    private:
        char Section;
        int Course;
        int QuizPoints = 0;
    
    public:
        
        SkillWillStudent(string Name, string Surname, int Age, string SubjectName, char Section, int Course){
            this->Name = Name;
            this->Surname = Surname;
            this->Age = Age;
            this->SubjectName = SubjectName;
            this->Section = Section;
            this->Course = Course;
        }
        
        int update(int point) {
            return QuizPoints += point;
        }
        
        void printPoints(){
            cout << Name << " " << Surname << " has " << QuizPoints << " points" << endl;
            cout << endl;
        }
        
        
        void attendLecture(){
            cout << Name << " " << Surname << " attends " << SubjectName << "'s lecture" << endl;
        }
        
        void attendLecture(string name, string subjectName){
            if(name == Name && subjectName == SubjectName){
                cout << Name << " " << Surname << " attends " << SubjectName << "'s lecture" << endl;
            } else {
                cout << "Wrong student's name or subject's name" << endl;
            }
        }

        // setter
        void setSection(char Section){
            this->Section = Section;
        }

        void setCourse(int Course){
            this->Course = Course;
        }

        void setQuizPoints(int QuizPoints){
            this->QuizPoints = QuizPoints;
        }

        // getter
        char getSection(){
            return Section;
        }

        int getCourse(){
            return Course;
        }

        int getQuizPoints(){
            return QuizPoints;
        }
};


int main()
{
    // ინფორმაცია ლექტორების შესახებ
    SkillWillSubject sub0("Php", "6 months", "11.11.22", "Information about php");
    SkillWillLecturer lec0("Lika", "Sikharulia", "Php", "Back-end", "Senior", sub0);
    
    SkillWillSubject sub1("Python", "4 months", "11.10.22", "Functions in Python");
    SkillWillLecturer lec1("Nugzar", "Mchedlishvili", "Python", "Back-end", "Senior", sub1);
    
    SkillWillSubject sub2("C++", "12 months", "10.10.22", "Pointers");
    SkillWillLecturer lec2("Alexander", "Kutaladze", "IOS", "Back-end", "Middle", sub2);
    
    lec0.conductingLecture("Back-end", "11.11.22");
    lec1.conductingLecture("Back-end", "11.10.22");
    lec2.conductingLecture("Back-end", "10.10.22");

    // ინფორმაცია სტუდენტების შესახებ
    SkillWillStudent stud0("Misho", "Rostomashvili", 22, "Python", 'b', 3);
    SkillWillStudent stud1("Tamta", "Tandashvili", 36, "Php", 'b', 0);
    
    
    stud0.attendLecture();
    stud0.update(34);
    stud0.update(11);
    stud0.printPoints();
    
    stud1.attendLecture("Tamta", "Php");
    stud1.update(45);
    stud1.update(20);
    stud1.printPoints();
    

    return 0;
}