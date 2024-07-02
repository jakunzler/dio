import { FiPlus } from "react-icons/fi";

import { Container, Brand, Menu, Search, Content, NewNote } from "./styles";

import { Header } from "../../components/Header";

import { ButtonText } from "../../components/ButtonText";

import { Input } from "../../components/Input";

import { Chatbot } from "../../components/Chatbot";

import { Section } from "../../components/Section";

export function Home() {
    return(
        <Container>
            <Brand>
                <h1>Marca</h1>
            </Brand>

            <Header />

            <Menu>
                <li>
                    <ButtonText 
                    title="Todos"
                />
                </li>

            </Menu>

            <Search>
                <Input 
                    placeholder="Pesquisar"
                />
            </Search>

            <Content>
                <Section title="Sessão" >
                 
                </ Section>
            </Content>

            <NewNote >
                <FiPlus />
                Nova

            </NewNote>

            <Chatbot />
        </Container>
    )
};