Exibir User por ID
SELECT * FROM usuario where ID_usuario = 1

Solicitação de amizade
insert into amizade(ID_usuario_req,ID_usuario_rec, Chave) values(1, 2, 0)

ver solicitações a de amizade
SELECT * FROM amizade where ID_usuario_rec = 2 and Chave = 0

aceitar Solicitação
UPDATE amizade set Chave = 1 where ID_usuario_req = 1 and ID_usuario_rec = 2


recusar Solicitação
DELETE FROM  amizade WHERE ID_usuario_req = 1 and ID_usuario_rec = 5

ver amigos
SELECT * FROM amizade WHERE (ID_usuario_rec = 1 or ID_usuario_req = 1) and Chave = 1


ver amigos em comum
SELECT * FROM amizade WHERE (ID_usuario_rec = 1 OR ID_usuario_req = 5) and Chave = 1

criar grupo
INSERT INTO mural(ID_mural) values(3)

INSERT INTO grupo(ID_grupo,ID_grupoMural, nome, dataDeCriacao) values(3, 3, "Eu amo Programar", 2018-11-01)
UPDATE `facebook_bd`.`grupo` SET `ID_grupoMural`='3', `nome`='Eu amo Programar' WHERE `ID_grupo`='3';


condição participante do grupo
// 0 = não participante com solicitação
// 1 = participante
// 2 = admin
INSERT INTO GrupoConf(ID_grupo, ID_usuario, Chave) VALUES(1 , 1 , 2)

tornar Adm
UPDATE GrupoConf set Chave = 2 WHERE ID_grupo = 1 and ID_usuario = 1

tirar Adm
UPDATE GrupoConf SET Chave = 1 WHERE ID_grupo = 1 and ID_usuario = 1

Remover do grupo 
UPDATE GrupoConf SET Chave = NULL WHERE ID_grupo = 1 and ID_usuario = 1

Ver membros do grupo 
SELECT * FROM GrupoConf WHERE (ID_grupo = 1 and (Chave = 1 or Chave = 2))

Ver Adms do grupo
SELECT * FROM GrupoConf WHERE (ID_grupo = 1 and  Chave = 2)

Mandar Solicitação para entrar no grupo
INSERT INTO GrupoConf(ID_grupo,ID_usuario,Chave) values(1 , 1 ,0)

Ver solicitações de entrar no grupo
SELECT * FROM GrupoConf WHERE (ID_grupo = 1 and Chave = 0)

Aceitar Solicitação
UPDATE GrupoConf SET Chave = 1 WHERE ID_grupo = 1 and ID_usuario = 1

/*Ver Grupos em comum
SELECT * FROM GrupoConf WHERE (ID_usuario_rec = 1 OR ID_usuario_req = 5) and Chave = 1*/

Criar Publicação 
INSERT INTO publicacao(ID_publicacao, ID_mural, ID_usuario, texto) values(1, 1 , 1, "to on no zap")


Criar comentario
INSERT INTO comentario(ID_comentario, ID_comentarioDoUsuario, ID_mural, ID_publicacao, texto) values(1, 2, 1 , 1, "to no zap kkkkk")

Criar reposta
INSERT INTO resposta(ID_resposta, ID_comentario, ID_mural, ID_usuario, ID_publicacao, resposta) values(1, 1, 6 , 3, 1, "emoji")


excluir resposta
DELETE FROM resposta WHERE ID_resposta = 1

excluir comentario
DELETE FROM resposta WHERE ID_resposta = 1
DELETE FROM comentario WHERE ID_comentario = 1

excluir Publicação
DELETE FROM resposta WHERE ID_resposta = 1
DELETE FROM comentario WHERE ID_comentario = 1
DELETE FROM publicacao WHERE ID_publicacao = 1














