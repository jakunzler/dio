import { SiReact } from "react-icons/si";
import { Container, Profile, Logout } from "./styles";
import emptyImage from "../../assets/empty-profile.png";

export function Header() {

    const avatarUrl = emptyImage;


    return(
        <Container>
            <Profile to="/profile">
                <img 
                src={avatarUrl} 
                alt={`Foto do usuário`}
            />

                <div>
                    <span>Bem vindo</span>
                </div>
            </Profile>

            <Logout>
                <SiReact />
            </Logout>
        </Container>
    )
}