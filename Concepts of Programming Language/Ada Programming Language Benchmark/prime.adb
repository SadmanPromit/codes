with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
procedure prime is
	N : Integer;
	Is_Prime : Boolean := True;
begin
	Put("Enter a number to check if it's a prime: ");
	Get(N);
	-- Check for prime number
	if N <= 1 then
		Is_Prime := False;
	else
		for I in 2.. N / 2 loop
			if N mod I = 0 then
				Is_Prime := False;
				exit;
			end if;
		end loop;
	end if;
	if Is_Prime then
		Put_Line(Integer'Image(N) & " is a prime number.");
	else
		Put_Line(Integer'Image(N) & " is not a prime number.");
	end if;
end prime;