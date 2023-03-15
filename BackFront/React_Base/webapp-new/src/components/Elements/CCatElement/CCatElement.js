import React from 'react'
import CButton from '../../UI/CButton/CButton'
import './CCatElement.css'

class CCatElement extends React.Component {
    render() {
        return (
            <div className="cat_container">
                <div className="cat_name">{this.props.product.medic_names}</div>
                <img src={this.props.product.img} width="200" height="100" className='cat_img'/>
                <div className="cat_cost">{this.props.product.medic_cost} руб 	</div>
                <CButton onClick={(e) => this.props?.onClick(e)} className="cat_button">Купить</CButton>
                <div className="cat_desc">{this.props.product.medic_count} штук</div>
            </div>
        )
    }
}

export default CCatElement