from django.urls import path, include
from .views import StudentViewSet, SemesterViewSet, CourseViewSet, AttendanceViewSet, GradeViewSet
from rest_framework.routers import DefaultRouter

router = DefaultRouter()
router.register('student', StudentViewSet, basename='student')
router.register('semester', SemesterViewSet, basename='semester')
router.register('course', CourseViewSet, basename='course')
router.register('attendance', AttendanceViewSet, basename='attendance')
router.register('grade', GradeViewSet, basename='grade')

urlpatterns = [
    path('', include(router.urls)),
    path('/<int:pk>/', include(router.urls)),
]
