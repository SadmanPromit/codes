function validateForm(){
  var username= document.getElementById("username").value;
  var password=document.getElementById("password").value;

  if(username.trim()=="")
  {
  	alert("please enter username!");
  	return false;
  }

  var chechkname=/nsu/gi;
  if(!username.trim().match(chechkname)){
  	alert("username must contain nsu");
  	return false;
  }
  var pass=/^[0-9a-zA-Z]{6,15}$/;
   if(!password.trim().match(pass)){
   	alert("wrong!!");
   	return false;
   }
  var strings=password.toString();
  var numeric=0;
  var upper=0;
  var character='';
  for(var i=0; i<strings.length; i++){
     character=strings.charAt(i);
       if(!isNaN(character)){
         numeric=1;
       }else if(character==character.toUpperCase())
         {upper=1;}
  }

  if(numeric==0 || upper ==0){
  	alert("pass must contain one numeric number and one upper case");
  	return false;
  }
   

  else 
  	return true;
}



