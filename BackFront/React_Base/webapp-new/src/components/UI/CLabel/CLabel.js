import React from 'react'
import './CLabel.css'

class CLabel extends React.Component {
    render() {
        return (
            <div>
                {this.props.children}
            </div>
        )
    }
}

export default CLabel