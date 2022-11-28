import * as AF from "../view/autorizationForm.js"
import * as RF  from "../view/registrationForm.js"
import * as MF from "../view/medicineList.js"

export function ProcessAutorizationForm(){
	let root = document.getElementById('root_point');
    AF.autorizationForm.renderSignIn(root);
}

export function ProcessRegistrationForm(){
	let root = document.getElementById('root_point');
    RF.registrationForm.renderSignUp(root);
}

export function ProcessMedicineList(medicine_list){
	let root = document.getElementById('root_point');
    MF.medicineList.renderCatalog(root, medicine_list);
}