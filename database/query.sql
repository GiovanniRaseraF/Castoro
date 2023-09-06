SET search_path to castorodb;
-- -----------------------------------------------------
-- Query insert_user
-- -----------------------------------------------------
INSERT INTO user (nome, cognome, discord_name, lista_soprannomi)
VALUES 
('lorenzo', 'mancini', 'manciolollo','mancio/sniccini'), 
('giovanni', 'rasera', 'cetriolinogio', 'cetriolino/mestolopiano');

-- -----------------------------------------------------
-- Query insert_story
-- -----------------------------------------------------
INSERT INTO stories (title, story_date, story, tag)
VALUES 
('fake', '2023-09-06', 'buonanotte ennio', 'mancio/cetriolino');

