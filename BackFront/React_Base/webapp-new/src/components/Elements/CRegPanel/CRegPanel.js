import React from 'react'
import CLabel from '../../UI/CLabel/CLabel'
import CTextBar from '../../UI/CTextBar/CTextBar'
import './CRegPanel.css'

class CRegPanel extends React.Component {
    state = {
        login: "",
        password: ""
    }

    onPasswordChange = (e) => {
        this.props?.onChange({
            ...this.state,
            password: e.currentTarget.value
        })

        this.setState({
            password: e.currentTarget.value
        })
    }

    onLoginChange = (e) => {
        this.props?.onChange({
            ...this.state,
            login: e.currentTarget.value
        })

        this.setState({
            login: e.currentTarget.value
        })
    }

    render() {
        return (
            <div align="center" className="regstr">
                <CLabel>Регистрация</CLabel>
                <br />
                <br />

                <CLabel>Логин</CLabel>
                <CTextBar value={this.state.login} onChange={this.onLoginChange} />

                <CLabel>Пароль</CLabel>
                <CTextBar value={this.state.password} onChange={this.onPasswordChange} />
            </div>
        )
    }
}

export default CRegPanel