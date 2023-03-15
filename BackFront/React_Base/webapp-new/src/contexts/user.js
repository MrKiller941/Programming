import React from 'react'

const value = {
   login: "",
   password: "",
   setUser() { }
}


export const UserContext = React.createContext(value)

class UserContextProvider extends React.Component {
   state = {
      login: "",
      password: ""
   }


   setUser({ login, password }) {
      this.setState({
         login,
         password
      })
   }

   render() {
      return <UserContext.Provider value={{
         login: this.state.login,
         password: this.state.password,
         setUser: this.setUser,
      }}>
         {this.props.children}
      </UserContext.Provider>
   }
}

export default UserContextProvider