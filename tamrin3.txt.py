students_list = [
    {
        "student_id": 1,
        "name": "Ali",
        "grades": [18, 19, 20]
    },
    {
        "student_id": 2,
        "name": "Zahra",
        "grades": [15, 14, 16.5]
    },
    {
        "student_id": 3,
        "name": "Reza",
        "grades": [12, 13, 11.5]
    }
]


def calculate_student_gpa(student):
    grades = student["grades"]
    avg = sum(grades) / len(grades)
    return avg


for student in students_list:
    gpa = calculate_student_gpa(student)
    print(f"Student: {student['name']}  |  GPA: {gpa:.2f}")