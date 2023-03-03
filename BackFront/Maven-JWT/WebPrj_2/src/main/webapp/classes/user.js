class User  { //Внутренний клас который выкидываем наружу через фабрику 
  
   constructor() {       
      this._userLogin = "";   
      this._userPassword = "";     
   } 
   
   setLogin(userLogin) {
      this._userLogin = userLogin;   
   }
   
   getLogin() {              
      return this._userLogin;      
   }
   
   
   setPassword(userPassword) {
      this._userPassword = userPassword;   
   }
   
   getPassword() {              
      return this._userPassword;      
   }
}



class UserFactory {
   
   static _user = null;
   
   static _createInstance() {
     return new User();      
   }
      
   static createInstance() {
      if (UserFactory._user === null) {
        UserFactory._user = UserFactory._createInstance();  
      }      
      return UserFactory._user;
   }
}



export {UserFactory};