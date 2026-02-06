weight, height = input().split()
weight = int(weight)
height = int(height)
height = height/100
BMI = weight/(height**2)
if BMI >= 40:
    print("Class III Obesity")
elif 35 <= BMI < 40 :
    print("Class II Obesity")
elif 30 <= BMI < 35 :
    print("Class I Obesity")
elif 25 <= BMI < 30 :
    print("Overweight")
elif 18.5 <= BMI < 25 :
    print("Normal Weight")
else:
    print("Below Normal Weight")