import React from 'react';
import { withRouter } from 'react-router-dom'
import CTextBar from '../../components/UI/CTextBar/CTextBar'
import CButton from '../../components/UI/CButton/CButton'
import CatalogService from '../../services/catalogService';
import "./CAddProdPage.css"

class CAddProdPage extends React.Component {
    state = {
        name: "",
        cost: "",
        img: "",
        count: "",
        message: ""
    }

    addProduct = async () => {
        const isOk = await CatalogService.postProduct({
            name: this.state.name,
            cost: this.state.cost,
            img: this.state.img,
            count: this.state.count,
        })

        if (!isOk) {
            this.setState({
                message: "Ошибка добавления в каталог."
            })
            return
        }

        this.setState({
            message: "Продукт успешно добавлен в каталог."
        })
    }


    back = () => {
        this.props.history.push("/catalog")
    }

    render() {
        return (
            <ul className="panel">
                <li>Название: <br /><CTextBar value={this.state.name} onChange={e => this.setState({ name: e.currentTarget.value })} /></li>
                <li>Стоимость:<br /><CTextBar value={this.state.cost} onChange={e => this.setState({ cost: e.currentTarget.value })} /></li>
                <li>Ссылка на изображение:<br /><CTextBar value={this.state.img} onChange={e => this.setState({ img: e.currentTarget.value })} /></li>
                <li>Количество:<br /><CTextBar value={this.state.count} onChange={e => this.setState({ count: e.currentTarget.value })} /></li>
                <li><CButton onClick={this.addProduct}>Отправить</CButton></li>
                <li><CButton onClick={this.back}>Назад</CButton></li>
                <div>{this.state.message && <><br />{this.state.message}</>}</div>
            </ul >
        )
    }
}

export default withRouter(CAddProdPage)