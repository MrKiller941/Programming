import React from 'react';
import { withRouter } from 'react-router-dom'
import CTextBar from '../../components/UI/CTextBar/CTextBar'
import CButton from '../../components/UI/CButton/CButton'
import CatalogService from '../../services/catalogService';
import "./CDeleteProdPage.css"

class CDeleteProdPage extends React.Component {
    state = {
        name: "",
        message: ""
    }

    deleteProduct = async () => {
        const isOk = await CatalogService.deleteProduct({
            name: this.state.name
        })

        if (!isOk) {
            this.setState({
                message: "Ошибка удаления."
            })
            return
        }

        this.setState({
            message: "Продукт успешно удален.."
        })
    }


    back = () => {
        this.props.history.push("/catalog")
    }

    render() {
        return (
            <ul className="panel">
                <li className="nm">Название:<br /><CTextBar value={this.state.name} onChange={(e) => this.setState({ name: e.currentTarget.value })} /></li>
                <li className="bt"><CButton onClick={this.deleteProduct}>Отправить</CButton></li>
                <li className="btBack"><CButton onClick={this.back}>Назад</CButton></li>
                <div className="message">{this.state.message && <><br /> {this.state.message}</>}</div>
            </ul>
        )
    }
}

export default withRouter(CDeleteProdPage)