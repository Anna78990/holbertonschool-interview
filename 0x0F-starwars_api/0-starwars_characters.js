#!/usr/bin/node

const request = require('request');

function characterLoop (character, i) {
  if (i === character.length) return;
    request(character[i], function (err, res, body) {
      if (err) console.log(err);
      else {
        console.log(JSON.parse(body).name);
        characterLoop(character, ++i);
      }
    });
}

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`,
  function (err, res, body) {
    if (err) console.log(err);
    else {
      const charters = JSON.parse(body).characters;
      characterLoop(charters, 0);
    }
  });
