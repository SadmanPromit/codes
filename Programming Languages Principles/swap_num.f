program swap_number_main
implicit none
real :: num1, num2
print *, 'Enter two numbers:'
read(*,*) num1, num2
call swap_num
write(*,*) num1, num2
contains
subroutine swap_num(x_first, y_second)
real :: x_first, y_second, temp
temp = x_first
x_first = y_second
y_second = temp
end subroutine swap_num
end program swap_number_main
