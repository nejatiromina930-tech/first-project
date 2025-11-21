class Student:
    def __init__(self,name):
        self.name=name
        self.grades_=[]
        
    def add_grade(self,grade):
        if 0<= grade <=20:
            self.grades_.append(grade)
        else:
            print("nomre bayad beyn 0 ta 20 bashad")

    def get_grades(self):
        return self.grades_

    def calculate_gpa(self):
        grades=self.get_grades()
        if len(grades)==0:
            return 0
        return sum(grades)/len(grades)

    def __str__(self):
        return f"name:{self.name}  **  moadel:{self.calculate_gpa():2f}"


name=input("nam daneshjou:")
student=Student(name)
count=int(input("tedad dorous ra vared kon"))
for i in range(count):
    grade=float(input(f"nomre{i+1}:"))
    student.add_grade(grade)
print(student)


           
        
