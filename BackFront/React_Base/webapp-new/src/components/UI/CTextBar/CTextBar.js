import React from 'react'
import './CTextBar.css'

class CTextBar extends React.Component {
    render() {
        return (
            <input type="text" className="textbar" style={this.props.style} value={this.props.value} onChange={(e) => this.props?.onChange(e)} />
        )
    }
}

export default CTextBar