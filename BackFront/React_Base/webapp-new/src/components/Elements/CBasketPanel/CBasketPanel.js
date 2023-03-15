import React from "react"
import CLabel from "../../UI/CLabel/CLabel"
import "./CBasketPanel.css"

class CBasketPanel extends React.Component {
    render() {
        return (
            <div className="dropdownContainer">
                <img src="/images/add-product.png" id="userImg" width="40" height="40" className="basketImage"></img>
                <div className="dropdownContent">
                    <div className="dropdownContentLineMessage">
                        {this.props.products.map((product, idx) => {
                            return <React.Fragment key={idx}>
                                {`${product.medic_names}  ${product.medic_cost} руб`} <br /><br />
                            </React.Fragment>
                        })}
                    </div>
                </div>
            </div>
        )
    }
}

export default CBasketPanel