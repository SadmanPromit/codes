from django.db import models

# Create your models here.


class Student(models.Model):
    FullName = models.CharField(max_length=120, default=0)
    StudentID = models.IntegerField(default=0)
    EnrolledIn = models.CharField(max_length=120, default=0)
    CurriculumName = models.CharField(max_length=120, default=0)
    EntryItem = models.CharField(max_length=120, default=0)
    TestPass = models.CharField(max_length=6, default=0)
    CurrentStatus = models.BooleanField(default=True)
    CGPA = models.IntegerField(default=0)
    CreditPassed = models.IntegerField(default=0)
    ProbationStatus = models.BooleanField(default=False)
    Major1 = models.CharField(max_length=120, default=0)
    Major2 = models.CharField(max_length=120, default=0)

    def __str__(self):
        return self.FullName


class Semester(Student):
    SemesterName = models.CharField(max_length=120, default=0)
    SemesterYear = models.IntegerField(default=0)

    def __str__(self):
        return self.SemesterName


class Course(Semester):
    CourseCode = models.CharField(max_length=8, default=0)
    CourseCredit = models.CharField(max_length=4, default=0)
    Section = models.IntegerField(default=0)
    CourseTitle = models.CharField(max_length=120, default=0)
    Day = models.CharField(max_length=2, default=0)
    StartTime = models.CharField(max_length=120, default=0)
    EndTime = models.CharField(max_length=120, default=0)
    Room = models.CharField(max_length=7, default=0)
    Faculty = models.CharField(max_length=120, default=0)

    def __str__(self):
        return self.CourseCode


class Attendance(Course):
    LectureNo = models.IntegerField(default=0)
    LectureDate = models.CharField(max_length=4, default=0)
    Attended = models.BooleanField(default=True)

    def __str__(self):
        return self.LectureNo


class Grade(Attendance):
    CourseGrade = models.CharField(max_length=1)
    CreditCount = models.IntegerField(default=0)
    CourseCreditPassed = models.IntegerField(default=0)