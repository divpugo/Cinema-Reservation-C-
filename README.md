# Parking Management System

## Introduction
This repository contains the C++ implementation of a parking management system designed for CST2550 Software Engineering Management and Development coursework. The system uses a hash table to manage parking spaces and a singly linked list to maintain a history of vehicle entries and exits.

## Features
- **Vehicle Entry and Exit Tracking:** Store and retrieve vehicles by their registration number, entry date, and time.
- **Reporting:** Access a historical report of vehicles parked on a specific date, including entry and exit times and parking fees.
- **Efficiency:** Implements hash tables for O(1) average time complexity on searches, insertions, and deletions under reasonable assumptions.

## Data Structures
- **Hash Table:** Used for storing vehicles entering the parking lot. Handles collisions and provides efficient data retrieval.
- **Singly Linked List:** Used for maintaining a historical record of vehicle movements and charges.

## Usage
1. **Adding a Vehicle:**
   - Vehicles are added to the hash table when they enter the parking lot.
2. **Searching for a Vehicle:**
   - Retrieve a vehicle’s information using its registration number.
3. **Removing a Vehicle:**
   - When vehicles exit, they are removed from the hash table and added to the linked list for historical tracking.
---

# Système de Gestion de Parking

## Introduction
Ce dépôt contient l'implémentation en C++ d'un système de gestion de parking conçu pour le cours CST2550 en Gestion et Développement du Génie Logiciel. Le système utilise une table de hachage pour gérer les espaces de stationnement et une liste chaînée simple pour maintenir un historique des entrées et sorties des véhicules.

## Fonctionnalités
- **Suivi des entrées et sorties des véhicules :** Enregistrer et récupérer les véhicules par leur numéro d'immatriculation, la date et l'heure d'entrée.
- **Rapport :** Accéder à un rapport historique des véhicules garés à une date spécifique, incluant les heures d'entrée et de sortie et les frais de stationnement.
- **Efficacité :** Implémentation de tables de hachage pour une complexité temporelle moyenne de O(1) pour les recherches, insertions et suppressions sous des hypothèses raisonnables.

## Structures de Données
- **Table de Hachage :** Utilisée pour stocker les véhicules entrant dans le parking. Gère les collisions et fournit une récupération efficace des données.
- **Liste Chaînée Simple :** Utilisée pour maintenir un enregistrement historique des mouvements des véhicules et des frais.

## Utilisation
1. **Ajout d'un véhicule :**
   - Les véhicules sont ajoutés à la table de hachage lorsqu'ils entrent dans le parking.
2. **Recherche d'un véhicule :**
   - Récupérer les informations d'un véhicule à l'aide de son numéro d'immatriculation.
3. **Retrait d'un véhicule :**
   - Lorsque les véhicules sortent, ils sont retirés de la table de hachage et ajoutés à la liste chaînée pour un suivi historique.
