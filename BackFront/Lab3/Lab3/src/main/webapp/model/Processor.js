var current_user_login = undefined;
var current_user_password = undefined;
var current_calatog = undefined;

function ProcessAutorization(){
	var login = document.getElementById("login_bar").value;
	var password = document.getElementById("password_bar").value;
	if(Transferclass.checkSignIn(login, password)){
		current_user_login = login;
		current_user_password = password;
		current_calatog = Transferclass.getCatalog();
		ProcessMedicineList(current_calatog);
	}else{
		createMessage("Неправильный логин или пароль.<br>");
	}
	
}


function ProcessRegistration(){
	var login = document.getElementById("reg_login_bar").value;
	var password = document.getElementById("reg_password_bar").value;
	if(Transferclass.trunSignUp(login, password)){
		ProcessAutorizationForm();
	}else{
		createMessage("Неверные данные для регистрации.<br>");
	}
}


function ProcessbyMedicines(id_key){
	// return Transferclass.getKey(id_key);
}