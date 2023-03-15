import React from 'react'
import CLabel from '../../UI/CLabel/CLabel'
import CTextBar from '../../UI/CTextBar/CTextBar'
import './CLogPanel.css'

class CLogPanel extends React.Component {
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
            <div align="center" id="c-log-panel" className="auth logPanel">
                <CLabel>Авторизация</CLabel>
                <br />
                <br />

                <CLabel>Логин</CLabel>
                <CTextBar
                    value={this.state.login}
                    onChange={this.onLoginChange}
                />

                <CLabel>Пароль</CLabel>
                <CTextBar
                    value={this.state.password}
                    onChange={this.onPasswordChange}
                />
            </div >
        )
    }
}

export default CLogPanel