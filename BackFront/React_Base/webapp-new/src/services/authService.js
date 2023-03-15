import config from '../configs/config.json'

class AuthService {
    static async signIn({ login, password }) {
        let res = await fetch(config.apiUrl + "/api/auth", {
            method: "POST",
            headers: { 'Content-Type': 'application/json;charset=utf-8' },
            body: JSON.stringify([login, password]),
        });

        return res.ok
    }

    static async signUp({ login, password }) {
        let res = await fetch(config.apiUrl + "/api/reg", {
            method: "POST",
            headers: { 'Content-Type': 'application/json;charset=utf-8' },
            body: JSON.stringify([login, password]),
            mode: "no-cors"
        });

        return res.ok
    }
}

export default AuthService