-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema PolTAXI
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS `PolTAXI` ;

-- -----------------------------------------------------
-- Schema PolTAXI
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `PolTAXI` DEFAULT CHARACTER SET utf8 ;
USE `PolTAXI` ;

-- -----------------------------------------------------
-- Table `PolTAXI`.`Pojazd`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Pojazd` (
  `Numer_rejestracyjny` VARCHAR(10) NOT NULL,
  `Numer_boczny` INT(3) NOT NULL AUTO_INCREMENT,
  `Marka` VARCHAR(15) NOT NULL,
  `Model` VARCHAR(45) NOT NULL,
  `Rocznik` YEAR NOT NULL,
  `Koniec_przegladu` DATE NOT NULL,
  `Osob` INT(1) UNSIGNED NOT NULL DEFAULT 4,
  PRIMARY KEY (`Numer_rejestracyjny`),
  UNIQUE INDEX `Numer_boczny_UNIQUE` (`Numer_boczny` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `PolTAXI`.`Kierowca`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Kierowca` (
  `PESEL` CHAR(11) NOT NULL,
  `Numer_rejestracyjny` VARCHAR(10) NOT NULL,
  `Imie` VARCHAR(20) NOT NULL,
  `Nazwisko` VARCHAR(45) NOT NULL,
  `Data_zatrudnienia` DATE NOT NULL,
  PRIMARY KEY (`PESEL`, `Numer_rejestracyjny`),
  UNIQUE INDEX `PESEL_UNIQUE` (`PESEL` ASC) VISIBLE,
  INDEX `fk_Kierowca_Pojazd_idx` (`Numer_rejestracyjny` ASC) VISIBLE,
  CONSTRAINT `fk_Kierowca_Pojazd`
    FOREIGN KEY (`Numer_rejestracyjny`)
    REFERENCES `PolTAXI`.`Pojazd` (`Numer_rejestracyjny`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `PolTAXI`.`Ubezpieczenie`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Ubezpieczenie` (
  `Numer_ubezpieczenia` VARCHAR(45) NOT NULL,
  `Numer_rejestracyjny` VARCHAR(10) NOT NULL,
  `Ubezpieczyciel` VARCHAR(45) NOT NULL,
  `Kwota` DECIMAL(8,2) UNSIGNED NOT NULL DEFAULT 0,
  `Koszt` DECIMAL(7,2) UNSIGNED NOT NULL DEFAULT 0,
  `OC` CHAR(1) NOT NULL DEFAULT 'T',
  `Data_zawarcia` DATE NOT NULL,
  `Data_zakonczenia` DATE NOT NULL,
  `AC` CHAR(1) NOT NULL DEFAULT 'N',
  `Dodatkowe_opcje` VARCHAR(160) NULL,
  PRIMARY KEY (`Numer_ubezpieczenia`, `Numer_rejestracyjny`),
  INDEX `fk_Ubezpieczenie_Pojazd1_idx` (`Numer_rejestracyjny` ASC) VISIBLE,
  UNIQUE INDEX `Numer_ubezpieczenia_UNIQUE` (`Numer_ubezpieczenia` ASC) VISIBLE,
  CONSTRAINT `fk_Ubezpieczenie_Pojazd1`
    FOREIGN KEY (`Numer_rejestracyjny`)
    REFERENCES `PolTAXI`.`Pojazd` (`Numer_rejestracyjny`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `PolTAXI`.`Warsztat`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Warsztat` (
  `Nazwa` VARCHAR(30) NOT NULL,
  `Adres` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Nazwa`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `PolTAXI`.`Naprawa`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Naprawa` (
  `Numer_faktury` VARCHAR(20) NOT NULL,
  `Data` DATE NOT NULL,
  `Nazwa` VARCHAR(30) NOT NULL,
  `Numer_rejestracyjny` VARCHAR(10) NOT NULL,
  `Opis` VARCHAR(160) NOT NULL,
  `Koszt` DECIMAL(7,2) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`Numer_faktury`, `Nazwa`, `Numer_rejestracyjny`, `Data`),
  INDEX `fk_Naprawa_Warsztat1_idx` (`Nazwa` ASC) VISIBLE,
  INDEX `fk_Naprawa_Pojazd1_idx` (`Numer_rejestracyjny` ASC) VISIBLE,
  CONSTRAINT `fk_Naprawa_Warsztat1`
    FOREIGN KEY (`Nazwa`)
    REFERENCES `PolTAXI`.`Warsztat` (`Nazwa`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Naprawa_Pojazd1`
    FOREIGN KEY (`Numer_rejestracyjny`)
    REFERENCES `PolTAXI`.`Pojazd` (`Numer_rejestracyjny`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `PolTAXI`.`Rejon`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Rejon` (
  `Nazwa` VARCHAR(25) NOT NULL,
  PRIMARY KEY (`Nazwa`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `PolTAXI`.`Obsluga`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Obsluga` (
  `Kierowca` CHAR(11) NOT NULL,
  `Rejon` VARCHAR(25) NOT NULL,
  PRIMARY KEY (`Kierowca`, `Rejon`),
  INDEX `fk_Kierowca_has_Rejon_Rejon1_idx` (`Rejon` ASC) VISIBLE,
  INDEX `fk_Kierowca_has_Rejon_Kierowca1_idx` (`Kierowca` ASC) VISIBLE,
  CONSTRAINT `fk_Kierowca_has_Rejon_Kierowca1`
    FOREIGN KEY (`Kierowca`)
    REFERENCES `PolTAXI`.`Kierowca` (`PESEL`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Kierowca_has_Rejon_Rejon1`
    FOREIGN KEY (`Rejon`)
    REFERENCES `PolTAXI`.`Rejon` (`Nazwa`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `PolTAXI`.`Ulica`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Ulica` (
  `Nazwa` VARCHAR(25) NOT NULL,
  `Rejon` VARCHAR(25) NOT NULL,
  PRIMARY KEY (`Nazwa`, `Rejon`),
  INDEX `fk_Ulica_Rejon1_idx` (`Rejon` ASC) VISIBLE,
  CONSTRAINT `fk_Ulica_Rejon1`
    FOREIGN KEY (`Rejon`)
    REFERENCES `PolTAXI`.`Rejon` (`Nazwa`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `PolTAXI`.`Klient`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Klient` (
  `Numer_telefonu` VARCHAR(15) NOT NULL,
  `email` VARCHAR(45) NOT NULL,
  `Data_rejestracji` DATE NOT NULL,
  `Imie` VARCHAR(20) NULL,
  `Nazwisko` VARCHAR(30) NULL,
  PRIMARY KEY (`Numer_telefonu`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `PolTAXI`.`Stawka`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Stawka` (
  `Kod` INT(3) NOT NULL,
  `Opis` VARCHAR(100) NOT NULL,
  `Cena_za_km` DECIMAL(4,2) NOT NULL DEFAULT 5,
  PRIMARY KEY (`Kod`),
  UNIQUE INDEX `Opis_UNIQUE` (`Opis` ASC) VISIBLE,
  UNIQUE INDEX `Kod_UNIQUE` (`Kod` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `PolTAXI`.`Przejazd`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Przejazd` (
  `Nr_paragonu` VARCHAR(25) NOT NULL,
  `PESEL` CHAR(11) NOT NULL,
  `Numer_telefonu` VARCHAR(15) NOT NULL,
  `Stawka_Kod` INT(3) NOT NULL,
  `Data_rozpoczecia` TIMESTAMP NOT NULL,
  `Dlugosc_trasy` DECIMAL(3,1) UNSIGNED NOT NULL DEFAULT 0,
  `Punkt_poczatkowy` VARCHAR(45) NOT NULL,
  `Punk_koncowy` VARCHAR(45) NOT NULL,
  `Czas_przejazdu` TIME NOT NULL DEFAULT '00:00:00',
  `Cena` DECIMAL(6,2) UNSIGNED NOT NULL DEFAULT 0,
  INDEX `fk_Przejazd_idx` (`Numer_telefonu` ASC) INVISIBLE,
  INDEX `fk_Przejazd_Stawka1_idx` (`Stawka_Kod` ASC) VISIBLE,
  INDEX `fk_Przejazd_Kierowca1_idx` (`PESEL` ASC) VISIBLE,
  PRIMARY KEY (`Nr_paragonu`),
  UNIQUE INDEX `dane_unikalne_przejazdu` (`PESEL` ASC, `Numer_telefonu` ASC, `Data_rozpoczecia` ASC) VISIBLE,
  CONSTRAINT `fk_Przejazd_Klient1`
    FOREIGN KEY (`Numer_telefonu`)
    REFERENCES `PolTAXI`.`Klient` (`Numer_telefonu`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Przejazd_Stawka1`
    FOREIGN KEY (`Stawka_Kod`)
    REFERENCES `PolTAXI`.`Stawka` (`Kod`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Przejazd_Kierowca1`
    FOREIGN KEY (`PESEL`)
    REFERENCES `PolTAXI`.`Kierowca` (`PESEL`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `PolTAXI`.`Promocja`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Promocja` (
  `Kod` VARCHAR(10) NOT NULL,
  `Nazwa` VARCHAR(45) NOT NULL,
  `Kwota_znizki` DECIMAL(4,2) UNSIGNED NOT NULL DEFAULT 0,
  `Procent_znizki` INT(2) UNSIGNED NULL DEFAULT 0,
  PRIMARY KEY (`Kod`),
  UNIQUE INDEX `Kod_UNIQUE` (`Kod` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `PolTAXI`.`Aktywowana_Promocja`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Aktywowana_Promocja` (
  `Kod` VARCHAR(10) NOT NULL,
  `Numer_telefonu` VARCHAR(15) NOT NULL,
  `Data_aktywacji` DATE NOT NULL,
  `Wykorzystanie` INT(1) UNSIGNED NOT NULL,
  `Przejazd_Nr_paragonu` VARCHAR(25) NULL,
  PRIMARY KEY (`Kod`, `Numer_telefonu`, `Data_aktywacji`),
  INDEX `fk_Promocja_has_Klient_Klient1_idx` (`Numer_telefonu` ASC) VISIBLE,
  INDEX `fk_Promocja_has_Klient_Promocja1_idx` (`Kod` ASC) VISIBLE,
  INDEX `fk_Aktywowana_Promocja_Przejazd1_idx` (`Przejazd_Nr_paragonu` ASC) VISIBLE,
  CONSTRAINT `fk_Promocja_has_Klient_Promocja1`
    FOREIGN KEY (`Kod`)
    REFERENCES `PolTAXI`.`Promocja` (`Kod`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Promocja_has_Klient_Klient1`
    FOREIGN KEY (`Numer_telefonu`)
    REFERENCES `PolTAXI`.`Klient` (`Numer_telefonu`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Aktywowana_Promocja_Przejazd1`
    FOREIGN KEY (`Przejazd_Nr_paragonu`)
    REFERENCES `PolTAXI`.`Przejazd` (`Nr_paragonu`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;

USE `PolTAXI` ;

-- -----------------------------------------------------
-- Placeholder table for view `PolTAXI`.`Pojazdy_z_ubezpieczeniem`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`Pojazdy_z_ubezpieczeniem` (`Numer_ubezpieczenia` INT, `Numer_rejestracyjny` INT, `Ubezpieczyciel` INT, `Kwota` INT, `Koszt` INT, `OC` INT, `Data_zawarcia` INT, `Data_zakonczenia` INT, `AC` INT, `Dodatkowe_opcje` INT, `Numer_boczny` INT, `Marka` INT, `Model` INT, `Rocznik` INT, `Koniec_przegladu` INT, `Osob` INT);

-- -----------------------------------------------------
-- Placeholder table for view `PolTAXI`.`KierowcyPojazdy`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `PolTAXI`.`KierowcyPojazdy` (`Numer_rejestracyjny` INT, `Numer_boczny` INT, `Marka` INT, `Model` INT, `Rocznik` INT, `Koniec_przegladu` INT, `Osob` INT, `PESEL` INT, `Imie` INT, `Nazwisko` INT, `Data_zatrudnienia` INT);

-- -----------------------------------------------------
-- procedure Dodaj_klienta
-- -----------------------------------------------------

DELIMITER $$
USE `PolTAXI`$$
CREATE PROCEDURE Dodaj_klienta (nr VARCHAR(15), e VARCHAR(45), rej DATE)
BEGIN
	INSERT INTO Klient(Numer_telefonu, email, Data_rejestracji)
		values(nr,em,rej);
END$$

DELIMITER ;

-- -----------------------------------------------------
-- function Najstarszy
-- -----------------------------------------------------

DELIMITER $$
USE `PolTAXI`$$
Create FUNCTION Najstarszy()
RETURNS VARCHAR(160) deterministic
BEGIN
DECLARE vw varchar(160);
DECLARE vpojazd INT; 
 SELECT MIN(Rocznik) INTO vpojazd from Pojazd;
 Select group_concat(Numer_rejestracyjny separator ' ') INTO vw from Pojazdy where Rocznik <= vpojazd;
return vw;
End ;$$

DELIMITER ;

-- -----------------------------------------------------
-- function Placa
-- -----------------------------------------------------

DELIMITER $$
USE `PolTAXI`$$
CREATE FUNCTION `Placa` (vID int(3),vod date, vdo date)
RETURNS DECIMAL deterministic
BEGIN
	DECLARE vPlaca,vZarobek,vPodstawa DECIMAL;
	DECLARE vPrzejazdow INT;
    SELECT Placa_podstawowa INTO vPodstawa FROM Kierowca WHERE idKierowcy=vID;
    SELECT COUNT(*),SUM(Cena) INTO vPrzejazdow,vZarobek FROM Przejazd 
		WHERE idKierowcy = vID AND Data_rozpoczecia <=vdo AND Data_rozpoczecia>= vod; 
	CASE
        WHEN vPrzejazdow>=640 THEN SET vPlaca = vPodstawa + vZarobek*0.10;
		WHEN vPrzejazdow<200 THEN SET vPlaca = vPodstawa;
        ELSE SET vPlaca = vPodstawa + vZarobek*0.08;
    END CASE;
    RETURN vPlaca;
END;$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure Dodaj_kierowce
-- -----------------------------------------------------

DELIMITER $$
USE `PolTAXI`$$
CREATE PROCEDURE `Dodaj_kierowce` (pes CHAR(11),nr varchar(11), im varchar(20), nazwisko varchar(25), zatr date)
BEGIN
IF zatr is null THEN
 SET zatr = CURRENT_DATE;
END IF;
INSERT INTO Kierowca(PESEL, Numer_rejestracyjny, Imie, Nazwisko, Data_zatrudnienia)
	VALUES(pes,nr,im,nazwisko,zatr);
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure Dodaj_pojazd
-- -----------------------------------------------------

DELIMITER $$
USE `PolTAXI`$$
CREATE PROCEDURE `Dodaj_pojazd` (nr_rej varchar(10), mar varchar(15), modelpoj varchar(45), rocznik year, przeg date, rej_osob int(1))
BEGIN
	INSERT INTO Pojazd(Numer_rejestracyjny, Marka, Model,Rocznik, Koniec_przegladu, Osob)
		VALUES(nr_rej, mar, modelpoj, rocznik, przeg, rej_osob);
END;$$

DELIMITER ;

-- -----------------------------------------------------
-- View `PolTAXI`.`Pojazdy_z_ubezpieczeniem`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `PolTAXI`.`Pojazdy_z_ubezpieczeniem`;
USE `PolTAXI`;
CREATE  OR REPLACE VIEW Pojazdy_z_ubezpieczeniem AS
	SELECT * FROM Pojazd NATURAL JOIN Ubezpieczenie;

-- -----------------------------------------------------
-- View `PolTAXI`.`KierowcyPojazdy`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `PolTAXI`.`KierowcyPojazdy`;
USE `PolTAXI`;
CREATE  OR REPLACE VIEW `KierowcyPojazdy` AS
	SELECT * FROM Kierowca natural join Pojazd;

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
