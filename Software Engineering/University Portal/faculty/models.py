from django.db import models


# Create your models here.


class Faculty(models.Model):
    FullName = models.CharField(max_length=120, default=0)
    FacultyID = models.IntegerField(default=0)
    Department = models.CharField(max_length=120, default=0)
    EntryItem = models.CharField(max_length=120, default=0)
    CurrentStatus = models.BooleanField(default=True)

    def __str__(self):
        return self.FullName
