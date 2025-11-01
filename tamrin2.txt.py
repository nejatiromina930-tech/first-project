def average(grades):
    return sum(grades) / len(grades)


count = int(input("Tedad dars-ha ra vared konid: "))

grades = []
for i in range(count):
    grade = float(input(f"Nomre dars {i + 1} ra vared konid: "))
    grades.append(grade)

avg = average(grades)

print(f"\nMiyangin nomre-ha: {avg:.2f}")

if avg >= 17:
    print("Vaziyat: Ali ")
elif avg >= 12:
    print("Vaziyat: Ghabool ")
else:
    print("Vaziyat: Mashroot ")