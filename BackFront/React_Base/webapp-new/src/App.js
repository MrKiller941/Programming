import React from "react";
import { Route, Switch } from "react-router-dom";
import CLogPage from "./pages/CLogPage/CLogPage";
import CRegPage from "./pages/CRegPage/CRegPage";
import CCatalogPage from "./pages/CCatalogPage/CCatalogPage";

import CAddProdPage from "./pages/CAddProdPage/CAddProdPage";
import CDeleteProdPage from "./pages/CDeleteProdPage/CDeleteProdPage";

class App extends React.Component {
  render() {
    return (
      <Switch>
        <Route exact path="/"><CLogPage /></Route>
        <Route path="/register"><CRegPage /></Route>
        <Route path="/catalog"><CCatalogPage /></Route>
        <Route path="/products/add"><CAddProdPage /></Route>
        <Route path="/products/delete"><CDeleteProdPage /></Route>
      </Switch>
    )
  }
}

export default App;
