import axios from 'axios';

export const gpt_api = `http://localhost:3333/api/prompt/`;

export const makeRequest = async (message) => {
    const { data } = await axios.post(gpt_api, message);
    return data;
};