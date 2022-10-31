function ProcessAutorizationForm(){
	var root = document.getElementById('root_point');
   autorizationForm.renderSignIn(root);
}

function ProcessRegistrationForm(){
	var root = document.getElementById('root_point');
   registrationForm.renderSignUp(root);
}

function ProcessMedicineList(medicine_list){
	var root = document.getElementById('root_point');
   medicineList.renderCatalog(root, medicine_list);
}