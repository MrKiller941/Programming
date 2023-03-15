import config from '../configs/config.json'

class CatalogService {
    static async getCatalog() {
        const res = await fetch(config.apiUrl + "/api/catalogs/medic-catalog", {
            method: "GET",
        });
        
        const json = await res.json();
        return json;
    }

    static async postProduct({ name, cost, count, img }) {
        const res = await fetch(config.apiUrl + "/api/catalogs/medic-catalog/add", {
            method: "POST",
            headers: { 'Content-Type': 'application/json;charset=utf-8' },
            body: JSON.stringify([name, cost, count, img]),
        });

        return res.ok
    }

    static async deleteProduct({ name }) {
        const res = await fetch(config.apiUrl + "/api/catalogs/medic-catalog/del", {
            method: 'POST',
            headers: { 'Content-Type': 'application/json;charset=utf-8' },
            body: JSON.stringify([name]),
        });

        return res.ok

    }
}

export default CatalogService