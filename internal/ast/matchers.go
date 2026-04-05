package ast

import (
	"errors"
	"strings"
)

type FriendsPhrase string

func (p *FriendsPhrase) Capture(values []string) error {
	v, err := capturePhrase(values, "circle of friends")
	if err != nil {
		return err
	}
	*p = FriendsPhrase(v)
	return nil
}

type JamPhrase string

func (p *JamPhrase) Capture(values []string) error {
	v, err := capturePhrase(values, "jam")
	if err != nil {
		return err
	}
	*p = JamPhrase(v)
	return nil
}

type AlbumsPhrase string

func (p *AlbumsPhrase) Capture(values []string) error {
	v, err := capturePhrase(values, "albums")
	if err != nil {
		return err
	}
	*p = AlbumsPhrase(v)
	return nil
}

var ErrUnexpectedPhrase = errors.New("unexpected phrase")

func capturePhrase(values []string, expected string) (string, error) {
	v := strings.Trim(values[0], "[]")
	if v != expected {
		return "", ErrUnexpectedPhrase
	}

	return v, nil
}
