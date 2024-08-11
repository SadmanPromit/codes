Program main
    implicit none
    real :: avg, a, b, c, d, cal_avg
    write(*,*) 'Enter three number', cal_avg
    read *, a, b, c, d
    avg = cal_avg(a, b, c, d)
    write(*,*) 'The three numbers', a, b, c, d
    write(*,*) 'Average is ', avg
End Program main

real  function cal_avg(w, x, y, z)
    real :: w, x, y, z, sum
    sum = w + x + y + z
    cal_avg = sum/4
    return
end function cal_avg
