$(document).ready(function(){
	//load_data();
	function load_data(query){
		$.ajax({
			
			method:"post",
			data:{query:query},
			success:function (data)
			{
				$('#result').html(data);
			},
			url:"fetch.php"
		});
	}

	$('#search_text').keyup(function(){
		var search = $(this).val();
		if(search != ''){
			load_data(search);
		}
		else{
			load_data();
		}
	});


});